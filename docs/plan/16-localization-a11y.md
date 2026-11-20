# 16 — Localization and accessibility

## Contract

Localization and accessibility are properties of the shared UI runtime and string pipeline, inherited by all three apps and all games. No user-facing text is a literal in code or markup. Every interactive node exposes an accessibility node automatically. Platform strings are owned by PokoX and shipped in the app; game strings are developer-authored and shipped in `.pkx`.

## String catalogs

CBOR map keyed by string id with plural and placeholder metadata.

```cbor
{
  "locale": "ar-SA",
  "entries": {
    "shop.buy": { "text": "اشترِ", "context": "button" },
    "wallet.balance": { "text": "الرصيد: {amount}", "placeholders": ["amount"] },
    "items.count": { "plural": {
      "zero": "لا عناصر", "one": "عنصر واحد", "two": "عنصران",
      "few": "{n} عناصر", "many": "{n} عنصرًا", "other": "{n} عنصر"
    }}
  }
}
```

All six CLDR plural categories supported. Placeholder sets validated across locales so translators cannot reorder them into nonsense. Naming: `scope.feature.element`, e.g. `app.publish.success`, `game.shop.title`.

## Extraction

From app markup with `@key` syntax, from `.ui.json` values starting with `@`, and from Mute `t("key", args)` builtins. A raw Mute string literal outside `t()` triggers a lint warning. Extraction produces a base catalog; missing translations fall back to base language, never to a key name.

## Translation workflow

Machine translation draft for all locales; placeholder and plural validation rejects bad drafts; community correction through a Cloudflare Pages web tool; developer accepts suggested translations for game strings; pseudo-localization in CI with expanded accented text finds hardcoded layout and clipping. Top languages get human review; the long tail stays machine-generated with community correction. This is a real quality ceiling of the $0 model.

## Runtime resolution

Locale from user setting, then OS locale, then en-US. Load compiled table, try language-only (`ar` from `ar-SA`), then base. Resolve key, apply plural rule, substitute placeholders, pass through font fallback. Missing keys log a warning and show the base value. Resolution cached by locale, key and args. Bindings to `@state` feed placeholders so a label follows a changing balance and stays translated.

## RTL

Layout anchors flip horizontally under RTL: Left and Right swap, Center stays. Paragraph direction from locale with bidi algorithm for mixed text. Directional icons mirror; non-directional ones do not. Numbers use CLDR digit shapes and separators. 9-slice left and right edges swap. Input caret and selection follow text direction. Pseudo-RTL CI flips every layout and checks for clipping.

## Font fallback

SDF font resolves a character through game font, platform font, system font. Missing everywhere shows a visible tofu box with the codepoint and a warning, never blank text. Glyph subsetting respects the chain: a game ships Latin and relies on platform fonts for CJK unless it bundles a CJK subset.

## Accessibility tree

Every interactive node exposes role from node type, label from bound string key, value from bound state, state flags (focused, disabled, selected, expanded), bounds from the layout solver and actions (activate, increment, decrement, select). Developers can override labels but cannot hide a node without an explicit `a11yHidden` flag, which triggers a review warning.

## Input accessibility

Remappable keyboard, gamepad and touch with 256 actions. Full keyboard traversal with visible 2 px focus ring. Gamepad D-pad navigates the tree. Hold or toggle for runnable actions. Reduced motion clamps animations. Color-blind-safe theme tokens; critical state never color-only. Font scale 100–200% with solver reflow. Optional audio cues for focus, success, error and warning.

## Platform hooks

Windows: UI Automation adapter, high-contrast detection, system font size, narrator. Android: AccessibilityNodeInfo, TalkBack, system font scale, switch access. Games expose the same tree through the engine.

## Data and limits

App binary holds platform tables; `.pkx` holds game tables and a11y labels; Postgres holds translation suggestions; local settings hold locale, font scale, remap, reduced motion and palette. Limits: 12 platform locales at launch, unlimited game locales, 50,000 strings/locale, fallback depth 3, 5,000 a11y nodes/screen.

# 13 — UI maker

## Contract

The UI maker edits `.ui.json` documents that compile into `.pkx` and render through the C++ retained-mode runtime. It is a visual authoring tool, not a runtime. Markup is separate from Mute logic. The tool emits data, never code. The runtime does not depend on Studio.

## Node schema

```json
{
  "id": "shopPanel",
  "type": "Panel",
  "layout": { "anchor": "Center", "width": 480, "height": "72%", "minWidth": 320 },
  "style": { "theme": "default", "bevel": true, "padding": 8 },
  "children": [
    { "id": "title", "type": "Label", "text": "@game.shop.title", "font": "heading" },
    { "id": "itemGrid", "type": "InventoryGrid", "columns": 5, "bind": "items" },
    { "id": "buyBtn", "type": "BevelButton", "text": "@game.shop.buy",
      "events": { "onClick": "buySelected" } }
  ]
}
```

A-tier nodes: Panel, Label, Image, BevelButton, GlossInput, Checkbox, Radio, ComboBox, Slider, ProgressBar, Scrollbar, ListView, InventoryGrid, TabStrip, Tooltip, Dialog, WindowFrame, TitleBar.

AA nodes: RichText, TreeView, MenuBar, SplitPane, Carousel, ColorPicker, FilePicker, Graph, VideoSurface, ToastArea.

Custom composite nodes are made of built-ins; no arbitrary native rendering.

## Layout solver

| Property | Behavior |
|---|---|
| anchor | TopLeft, Top, TopRight, Left, Center, Right, BottomLeft, Bottom, BottomRight, Stretch |
| offset | Pixels or percentage from anchor |
| width/height | Fixed, percentage of parent, or fill |
| min/max | Clamps that win over fill |
| padding/margin | dp insets |
| constraints | Optional relations such as `a.right == b.left` |
| safeArea | Android cutouts respected by default |

Solver runs top-down then bottom-up, is deterministic and resolution-independent. Circular constraints are rejected at compile time. A layout inspector overlays computed bounds, anchors and conflicts.

## State binding

| Binding | Direction | Example |
|---|---|---|
| bind | one-way read | Label follows `@state var score` |
| bindTwoWay | read and write | Input edits `@state var search` |
| visible | boolean expression | Panel shown when `balance > 0` |
| events.onClick | UI to Mute | Button calls `@on(BuyPressed)` |
| listSource | collection | Grid repeats from `@state var items` |

Bindings resolve by name against Mute `@state` symbols. A missing symbol is a compile error. Two-way bind to a `ServerOwned` field is rejected by the compiler. RTL flips anchors; `Left` and `Right` swap, `Center` stays.

## Style and 9-slice

```json
"style": {
  "theme": "default",
  "nineSlice": { "image": "panel_frame.png", "left": 8, "top": 8, "right": 8, "bottom": 8 },
  "states": {
    "normal":   { "tint": "#ffffff" },
    "hover":    { "tint": "#fff2d0" },
    "pressed":  { "tint": "#dddddd", "offsetY": 1 },
    "disabled": { "tint": "#888888" }
  }
}
```

The 9-slice editor shows nine regions with draggable guides. State tints and offsets are token-driven. Poko Classic ships as an optional example, not an imposed default.

## Editor panels

Canvas: WYSIWYG, rulers, grid snap, anchor guides, multi-select, drag reorder, 9-slice handles. Tree: component hierarchy with lock and rename. Inspector: typed property grid, token dropdowns, binding autocomplete from Mute symbols. Events panel: event-to-handler mapping with jump to function. State panel: lists `@state` symbols; drag onto a property to bind. Preview: live UI with device presets and simulated inputs. Hot reload: saving a patch applies in under 200 ms without resetting `@state`. Layout inspector: computed bounds overlay.

All edits are undoable. Tool saves continuously to `.pk`; publish remains the signed pipeline.

## Runtime compilation

`.ui.json` -> UI IR with resolved bindings and flattened constraints -> binary UI data in `.pkx` with a version hash. Runtime builds the tree once, re-resolves only on state change or resize. No JSON parsing at runtime. Bindings are stored as symbol indices, so renaming a Mute variable breaks the build.

## Difference from app interface

| | App interface | UI maker output |
|---|---|---|
| Owner | PokoX | Developer |
| Style | Fixed 2008 Classic tokens | Developer choice |
| Lives in | App binary | `.pkx` |
| Change control | Our releases | Developer publish |
| Skin | Classic / Flat | Any theme tokens |

## Limits

5,000 nodes/screen, tree depth 32, 16 bindable properties/node, 8 theme sets/game, 4,096 px 9-slice texture, 20 concurrent animations, 64 screens/game, 512 constraints/screen, hot reload under 200 ms.

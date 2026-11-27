//! SHL-12: theme tokens for PokoX Windows shell (`Classic` 2008 bevel and
//! `Flat` modern). Zero corner rounding, 1 px bevel strokes, WCAG-legible
//! contrast, and deterministic `egui::Style` construction.

use egui::{Color32, CornerRadius, Stroke, Style, Visuals};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ThemeKind {
    Classic = 0,
    Flat = 1,
}

#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ThemeTokens {
    pub kind: ThemeKind,
    pub bg_panel: Color32,
    pub bg_widget: Color32,
    pub bg_widget_hover: Color32,
    pub bg_widget_active: Color32,
    pub gradient_top: Color32,
    pub gradient_bottom: Color32,
    pub bevel_light: Color32,
    pub bevel_dark: Color32,
    pub text_primary: Color32,
    pub text_muted: Color32,
    pub accent: Color32,
    pub stroke_width: f32,
}

impl ThemeTokens {
    pub const fn classic() -> Self {
        Self {
            kind: ThemeKind::Classic,
            bg_panel: Color32::from_rgb(236, 233, 216),
            bg_widget: Color32::from_rgb(225, 222, 206),
            bg_widget_hover: Color32::from_rgb(238, 244, 252),
            bg_widget_active: Color32::from_rgb(200, 214, 232),
            gradient_top: Color32::from_rgb(252, 252, 250),
            gradient_bottom: Color32::from_rgb(212, 208, 192),
            bevel_light: Color32::from_rgb(255, 255, 255),
            bevel_dark: Color32::from_rgb(128, 128, 120),
            text_primary: Color32::from_rgb(18, 18, 20),
            text_muted: Color32::from_rgb(80, 80, 84),
            accent: Color32::from_rgb(49, 106, 197),
            stroke_width: 1.0,
        }
    }

    pub const fn flat() -> Self {
        Self {
            kind: ThemeKind::Flat,
            bg_panel: Color32::from_rgb(30, 32, 36),
            bg_widget: Color32::from_rgb(44, 47, 54),
            bg_widget_hover: Color32::from_rgb(56, 60, 70),
            bg_widget_active: Color32::from_rgb(36, 38, 44),
            gradient_top: Color32::from_rgb(44, 47, 54),
            gradient_bottom: Color32::from_rgb(44, 47, 54),
            bevel_light: Color32::from_rgb(72, 76, 86),
            bevel_dark: Color32::from_rgb(72, 76, 86),
            text_primary: Color32::from_rgb(240, 242, 245),
            text_muted: Color32::from_rgb(168, 174, 184),
            accent: Color32::from_rgb(76, 142, 245),
            stroke_width: 1.0,
        }
    }

    pub const fn for_kind(kind: ThemeKind) -> Self {
        match kind {
            ThemeKind::Classic => Self::classic(),
            ThemeKind::Flat => Self::flat(),
        }
    }

    pub fn to_egui_style(&self) -> Style {
        let mut style = Style::default();
        let mut visuals = match self.kind {
            ThemeKind::Classic => Visuals::light(),
            ThemeKind::Flat => Visuals::dark(),
        };

        visuals.window_corner_radius = CornerRadius::ZERO;
        visuals.menu_corner_radius = CornerRadius::ZERO;
        visuals.panel_fill = self.bg_panel;
        visuals.window_fill = self.bg_panel;
        visuals.extreme_bg_color = self.bg_widget_active;
        visuals.override_text_color = Some(self.text_primary);
        visuals.window_stroke = Stroke::new(self.stroke_width, self.bevel_dark);

        let stroke = Stroke::new(self.stroke_width, self.bevel_dark);
        let accent_stroke = Stroke::new(self.stroke_width, self.accent);

        visuals.widgets.noninteractive.corner_radius = CornerRadius::ZERO;
        visuals.widgets.noninteractive.bg_fill = self.bg_panel;
        visuals.widgets.noninteractive.bg_stroke = stroke;
        visuals.widgets.noninteractive.fg_stroke = Stroke::new(1.0, self.text_primary);

        visuals.widgets.inactive.corner_radius = CornerRadius::ZERO;
        visuals.widgets.inactive.bg_fill = self.bg_widget;
        visuals.widgets.inactive.bg_stroke = stroke;
        visuals.widgets.inactive.fg_stroke = Stroke::new(1.0, self.text_primary);

        visuals.widgets.hovered.corner_radius = CornerRadius::ZERO;
        visuals.widgets.hovered.bg_fill = self.bg_widget_hover;
        visuals.widgets.hovered.bg_stroke = accent_stroke;
        visuals.widgets.hovered.fg_stroke = Stroke::new(1.0, self.text_primary);

        visuals.widgets.active.corner_radius = CornerRadius::ZERO;
        visuals.widgets.active.bg_fill = self.bg_widget_active;
        visuals.widgets.active.bg_stroke = accent_stroke;
        visuals.widgets.active.fg_stroke = Stroke::new(1.0, self.text_primary);

        visuals.widgets.open.corner_radius = CornerRadius::ZERO;
        visuals.widgets.open.bg_fill = self.bg_widget_hover;
        visuals.widgets.open.bg_stroke = accent_stroke;
        visuals.widgets.open.fg_stroke = Stroke::new(1.0, self.text_primary);

        style.visuals = visuals;
        style
    }
}

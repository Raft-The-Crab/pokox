//! SHL-12: 2008-style bevel and gloss widgets (`PokoBevelButton`,
//! `PokoGlossPanel`, `PokoTabStrip`) driven by `ThemeTokens`.

use egui::epaint::{Mesh, Vertex};
use egui::{Align2, Color32, FontId, Pos2, Rect, Response, Sense, Stroke, Ui, Vec2};

use crate::theme::ThemeTokens;

fn paint_vertical_gradient(ui: &Ui, rect: Rect, top: Color32, bottom: Color32) {
    let mut mesh = Mesh::default();
    let uv = Pos2::ZERO;
    mesh.vertices.push(Vertex { pos: rect.left_top(), uv, color: top });
    mesh.vertices.push(Vertex { pos: rect.right_top(), uv, color: top });
    mesh.vertices.push(Vertex { pos: rect.right_bottom(), uv, color: bottom });
    mesh.vertices.push(Vertex { pos: rect.left_bottom(), uv, color: bottom });
    mesh.indices.extend_from_slice(&[0, 1, 2, 0, 2, 3]);
    ui.painter().add(egui::Shape::mesh(mesh));
}

fn paint_bevel_border(ui: &Ui, rect: Rect, light: Color32, dark: Color32, width: f32) {
    let p = ui.painter();
    let inset = rect.shrink(0.5);
    p.line_segment([inset.left_bottom(), inset.left_top()], Stroke::new(width, light));
    p.line_segment([inset.left_top(), inset.right_top()], Stroke::new(width, light));
    p.line_segment([inset.right_top(), inset.right_bottom()], Stroke::new(width, dark));
    p.line_segment([inset.right_bottom(), inset.left_bottom()], Stroke::new(width, dark));
}

pub struct PokoBevelButton<'a> {
    label: &'a str,
    tokens: &'a ThemeTokens,
}

impl<'a> PokoBevelButton<'a> {
    pub fn new(label: &'a str, tokens: &'a ThemeTokens) -> Self {
        Self { label, tokens }
    }

    pub fn show(self, ui: &mut Ui) -> Response {
        let desired = Vec2::new(88.0, 22.0);
        let (rect, response) = ui.allocate_exact_size(desired, Sense::click());
        if ui.is_rect_visible(rect) {
            let (top, bottom, tl, br) = if response.is_pointer_button_down_on() {
                (
                    self.tokens.bg_widget_active,
                    self.tokens.bg_widget_active,
                    self.tokens.bevel_dark,
                    self.tokens.bevel_light,
                )
            } else if response.hovered() {
                (
                    self.tokens.bg_widget_hover,
                    self.tokens.gradient_bottom,
                    self.tokens.bevel_light,
                    self.tokens.accent,
                )
            } else {
                (
                    self.tokens.gradient_top,
                    self.tokens.gradient_bottom,
                    self.tokens.bevel_light,
                    self.tokens.bevel_dark,
                )
            };
            paint_vertical_gradient(ui, rect, top, bottom);
            paint_bevel_border(ui, rect, tl, br, self.tokens.stroke_width);
            ui.painter().text(
                rect.center(),
                Align2::CENTER_CENTER,
                self.label,
                FontId::proportional(12.0),
                self.tokens.text_primary,
            );
        }
        response
    }
}

pub struct PokoGlossPanel<'a> {
    tokens: &'a ThemeTokens,
}

impl<'a> PokoGlossPanel<'a> {
    pub fn new(tokens: &'a ThemeTokens) -> Self {
        Self { tokens }
    }

    pub fn show<R>(self, ui: &mut Ui, add_contents: impl FnOnce(&mut Ui) -> R) -> R {
        let frame = egui::Frame::NONE
            .fill(self.tokens.bg_panel)
            .stroke(Stroke::new(self.tokens.stroke_width, self.tokens.bevel_dark))
            .inner_margin(6.0);
        frame
            .show(ui, |ui| {
                let header_rect = Rect::from_min_size(
                    ui.cursor().min,
                    Vec2::new(ui.available_width().max(64.0), 4.0),
                );
                paint_vertical_gradient(
                    ui,
                    header_rect,
                    self.tokens.gradient_top,
                    self.tokens.gradient_bottom,
                );
                add_contents(ui)
            })
            .inner
    }
}

pub struct PokoTabStrip<'a> {
    tabs: &'a [&'a str],
    selected: &'a mut usize,
    tokens: &'a ThemeTokens,
}

impl<'a> PokoTabStrip<'a> {
    pub fn new(tabs: &'a [&'a str], selected: &'a mut usize, tokens: &'a ThemeTokens) -> Self {
        Self { tabs, selected, tokens }
    }

    pub fn show(self, ui: &mut Ui) {
        ui.horizontal(|ui| {
            for (idx, title) in self.tabs.iter().enumerate() {
                let is_active = idx == *self.selected;
                let (rect, resp) = ui.allocate_exact_size(Vec2::new(64.0, 20.0), Sense::click());
                if resp.clicked() {
                    *self.selected = idx;
                }
                if ui.is_rect_visible(rect) {
                    let (top, bottom) = if is_active {
                        (self.tokens.bg_panel, self.tokens.gradient_top)
                    } else {
                        (self.tokens.gradient_top, self.tokens.gradient_bottom)
                    };
                    paint_vertical_gradient(ui, rect, top, bottom);
                    paint_bevel_border(
                        ui,
                        rect,
                        if is_active { self.tokens.accent } else { self.tokens.bevel_light },
                        self.tokens.bevel_dark,
                        self.tokens.stroke_width,
                    );
                    ui.painter().text(
                        rect.center(),
                        Align2::CENTER_CENTER,
                        *title,
                        FontId::proportional(11.0),
                        if is_active { self.tokens.text_primary } else { self.tokens.text_muted },
                    );
                }
            }
        });
    }
}

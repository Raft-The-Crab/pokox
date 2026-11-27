//! Interactive Windows preview of the PokoX egui shell (`SHL-12` themes,
//! bevel/gloss widgets, tab strip, and CJK text input).
//!
//! Build:
//!   cargo +stable-x86_64-pc-windows-msvc build --release --example preview --target x86_64-pc-windows-msvc

use eframe::egui;
use poko_shell::theme::{ThemeKind, ThemeTokens};
use poko_shell::widgets::{PokoBevelButton, PokoGlossPanel, PokoTabStrip};

struct PreviewApp {
    theme: ThemeKind,
    active_tab: usize,
    input_text: String,
    play_clicks: u32,
}

impl Default for PreviewApp {
    fn default() -> Self {
        Self {
            theme: ThemeKind::Classic,
            active_tab: 0,
            input_text: "PokoX".to_owned(),
            play_clicks: 0,
        }
    }
}

impl eframe::App for PreviewApp {
    fn ui(&mut self, ui: &mut egui::Ui, _frame: &mut eframe::Frame) {
        let tokens = ThemeTokens::for_kind(self.theme);
        ui.ctx().set_style_of(egui::Theme::Light, ThemeTokens::classic().to_egui_style());
        ui.ctx().set_style_of(egui::Theme::Dark, ThemeTokens::flat().to_egui_style());
        ui.ctx().set_theme(match self.theme {
            ThemeKind::Classic => egui::Theme::Light,
            ThemeKind::Flat => egui::Theme::Dark,
        });

        egui::CentralPanel::default()
            .frame(egui::Frame::NONE.fill(tokens.bg_panel).inner_margin(10.0))
            .show(ui, |ui| {
                PokoGlossPanel::new(&tokens).show(ui, |ui| {
                    ui.horizontal(|ui| {
                        PokoTabStrip::new(
                            &["Library", "Store", "Studio"],
                            &mut self.active_tab,
                            &tokens,
                        )
                        .show(ui);
                        ui.add_space(12.0);
                        let toggle_label = match self.theme {
                            ThemeKind::Classic => "Theme: Classic",
                            ThemeKind::Flat => "Theme: Flat",
                        };
                        if PokoBevelButton::new(toggle_label, &tokens).show(ui).clicked() {
                            self.theme = match self.theme {
                                ThemeKind::Classic => ThemeKind::Flat,
                                ThemeKind::Flat => ThemeKind::Classic,
                            };
                        }
                    });

                    ui.add_space(8.0);
                    ui.label(format!(
                        "PokoX Shell Preview — Tab: {}",
                        ["Library", "Store", "Studio"][self.active_tab]
                    ));
                    ui.add_space(6.0);

                    ui.horizontal(|ui| {
                        ui.label("Text / IME:");
                        ui.add(
                            egui::TextEdit::singleline(&mut self.input_text)
                                .desired_width(220.0),
                        );
                        if PokoBevelButton::new("Play", &tokens).show(ui).clicked() {
                            self.play_clicks += 1;
                        }
                    });

                    ui.add_space(6.0);
                    ui.label(format!(
                        "Play clicked: {} | Pixels per point: {:.2}",
                        self.play_clicks,
                        ui.ctx().pixels_per_point()
                    ));
                });

                ui.add_space(10.0);
                let avail = ui.available_size();
                let (vp_rect, _) = ui.allocate_exact_size(
                    egui::Vec2::new(avail.x.max(120.0), avail.y.max(120.0)),
                    egui::Sense::hover(),
                );
                ui.painter().rect_filled(
                    vp_rect,
                    egui::CornerRadius::ZERO,
                    egui::Color32::from_rgb(18, 24, 34),
                );
                ui.painter().rect_stroke(
                    vp_rect,
                    egui::CornerRadius::ZERO,
                    egui::Stroke::new(1.0, tokens.bevel_dark),
                    egui::StrokeKind::Inside,
                );
                ui.painter().text(
                    vp_rect.center(),
                    egui::Align2::CENTER_CENTER,
                    "Game Viewport (Vulkan / RHI surface target)",
                    egui::FontId::proportional(14.0),
                    egui::Color32::from_rgb(160, 175, 195),
                );
            });
    }
}

fn main() -> eframe::Result<()> {
    let options = eframe::NativeOptions {
        viewport: egui::ViewportBuilder::default()
            .with_inner_size([800.0, 520.0])
            .with_title("PokoX Shell Preview (SHL-12)"),
        ..Default::default()
    };
    eframe::run_native(
        "PokoX Shell Preview",
        options,
        Box::new(|_cc| Ok(Box::new(PreviewApp::default()))),
    )
}

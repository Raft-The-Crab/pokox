#include <catch2/catch_test_macros.hpp>
#include <SDL3/SDL.h>
#include <imgui.h>
#include <spdlog/spdlog.h>
#include <EngineFactoryBase.hpp>

TEST_CASE("dependency libraries are available", "[build]") {
    REQUIRE(SDL_GetVersion() > 0);
    REQUIRE(ImGui::GetVersion() != nullptr);
    REQUIRE(Diligent::GetAPIInfo().APIVersion == DILIGENT_API_VERSION);
    spdlog::info("PokoX dependency smoke test");
}

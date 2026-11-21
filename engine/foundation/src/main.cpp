#include "poko/foundation/build_flags.hpp"
#include "poko/build_version.hpp"

#include <iostream>
#include <string_view>

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string_view{argv[1]} == "--version") {
        std::cout << "PokoX build: " << poko::build::version << '\n';
    } else if (argc == 2 && std::string_view{argv[1]} == "--build-info") {
        std::cout << "POKO_IMGUI=" << poko::build::imgui << '\n'
                  << "POKO_D3D12=" << poko::build::d3d12 << '\n'
                  << "POKO_DEBUG=" << poko::build::debug << '\n';
    }
    return 0;
}

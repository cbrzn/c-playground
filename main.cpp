#include <iostream>
#include <vector>
#include <memory>

extern "C" {
    #include "lib/headers.hpp"
}

int main() {
//    const char* builder = create_builder();
//    const char* redirect_static_resolver = create_static_resolver(
//        "ens/add.eth",
//        "wrap://http/https://raw.githubusercontent.com/polywrap/wasm-test-harness/v0.2.1/wrappers/subinvoke/00-subinvoke/implementations/as"
//    );
//   add_static_resolver(builder, redirect_static_resolver);
//    const char* resolver = build_resolver(builder);

    const char* resolver = create_resolver();

    const char* client = create_client(resolver);
    struct Buffer result = invoke(
            client,
            "wrap://http/https://raw.githubusercontent.com/polywrap/wasm-test-harness/v0.2.1/wrappers/subinvoke/00-subinvoke/implementations/as",
            "add",
            "{\"a\":1,\"b\":1}"
    );


    std::vector<uint8_t> vec(result.data, result.data + result.len);
    for (uint8_t val : vec) {
        std::cout << val << " ";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

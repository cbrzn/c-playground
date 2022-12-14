#include <iostream>
#include <vector>

extern "C" {
    #include "lib/rust-client/packages/ffi-swift/include/headers.h"
}


int main() {
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

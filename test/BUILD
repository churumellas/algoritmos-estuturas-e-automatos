load("@rules_cc//cc:defs.bzl","cc_test")
cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src:lista-simples",
        "//src:lista-dupla",
        "@googletest//:gtest_main",
    ],
)
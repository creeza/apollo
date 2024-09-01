#编译hello_great 库
#package(default_visibility = ["//visibility:public"])
cc_library(
    name = "hello_great_lib",
    srcs = ["hello_great.cc"],
    hdrs = ["hello_great.h"],
    visibility = ["//demo_main:__pkg__"]
)

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [":hello_great_lib"]
)
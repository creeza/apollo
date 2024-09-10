#load("//tools:python_rules.bzl", "py_proto_library")
package(default_visibility = ["//visibility:public"])
#-----------------------------------
# 生成proto 库
proto_library(
    name = "student_proto",
    srcs = ["student.proto"]
)
# 生成C++相关的源文件
cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"]
)
#-----------------------------------
#配置C++调用proto实现
cc_binary(
    name = "test_student",
    srcs = ["test_student.cc"],
    deps = [":student_cc"]
)
#-----------------------------------
proto_library(
    name = "addints_proto",
    srcs = ["addints.proto"],
)

cc_proto_library(
    name = "addints_cc",
    deps = [":addints_proto"]
)
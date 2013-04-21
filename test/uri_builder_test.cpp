// Copyright (c) Glyn Matthews 2012, 2013.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <gtest/gtest.h>
#include <network/uri.hpp>
#include "string_utility.hpp"

TEST(builder_test, empty_uri_doesnt_throw) {
  network::uri_builder builder;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, empty_uri) {
  network::uri_builder builder;
  network::uri instance(builder);
  ASSERT_TRUE(instance.empty());
}

TEST(builder_test, simple_uri_doesnt_throw) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, simple_uri) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("http://www.example.com/", network::uri(builder));
}

TEST(builder_test, simple_uri_has_scheme) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_TRUE(network::uri(builder).scheme());
}

TEST(builder_test, simple_uri_scheme_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("http", *network::uri(builder).scheme());
}

TEST(builder_test, simple_uri_has_no_user_info) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_FALSE(network::uri(builder).user_info());
}

TEST(builder_test, simple_uri_has_host) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_TRUE(network::uri(builder).host());
}

TEST(builder_test, simple_uri_host_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("www.example.com", *network::uri(builder).host());
}

TEST(builder_test, simple_uri_has_no_port) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_FALSE(network::uri(builder).port());
}

TEST(builder_test, simple_uri_has_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_TRUE(network::uri(builder).path());
}

TEST(builder_test, simple_uri_path_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("/", *network::uri(builder).path());
}

TEST(builder_test, simple_uri_has_no_query) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_FALSE(network::uri(builder).query());
}

TEST(builder_test, simple_uri_has_no_fragment) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_FALSE(network::uri(builder).fragment());
}

TEST(builder_test, simple_opaque_uri_doesnt_throw) {
  network::uri_builder builder;
  builder
    .scheme("mailto")
    .path("john.doe@example.com")
    ;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, simple_opaque_uri) {
  network::uri_builder builder;
  builder
    .scheme("mailto")
    .path("john.doe@example.com")
    ;
  ASSERT_EQ("mailto:john.doe@example.com", network::uri(builder));
}

TEST(builder_test, simple_opaque_uri_has_scheme) {
  network::uri_builder builder;
  builder
    .scheme("mailto")
    .path("john.doe@example.com")
    ;
  ASSERT_TRUE(network::uri(builder).scheme());
}

TEST(builder_test, simple_opaque_uri_scheme_value) {
  network::uri_builder builder;
  builder
    .scheme("mailto")
    .path("john.doe@example.com")
    ;
  ASSERT_EQ("mailto", *network::uri(builder).scheme());
}

TEST(builder_test, relative_hierarchical_uri_doesnt_throw) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, relative_hierarchical_uri) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("www.example.com/", network::uri(builder));
}

TEST(builder_test, relative_opaque_uri_doesnt_throw) {
  network::uri_builder builder;
  builder
    .path("john.doe@example.com")
    ;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, relative_opaque_uri) {
  network::uri_builder builder;
  builder
    .path("john.doe@example.com")
    ;
  ASSERT_EQ("john.doe@example.com", network::uri(builder));
}

TEST(builder_test, full_uri_doesnt_throw) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_NO_THROW(network::uri(builder));
}

TEST(builder_test, full_uri) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("http://user:password@www.example.com:80/path?query#fragment", network::uri(builder));
}

TEST(builder_test, full_uri_has_scheme) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).scheme());
}

TEST(builder_test, full_uri_scheme_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("http", *network::uri(builder).scheme());
}

TEST(builder_test, full_uri_has_user_info) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).user_info());
}

TEST(builder_test, full_uri_user_info_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("user:password", *network::uri(builder).user_info());
}

TEST(builder_test, full_uri_has_host) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).host());
}

TEST(builder_test, full_uri_host_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("www.example.com", *network::uri(builder).host());
}

TEST(builder_test, full_uri_has_port) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).port());
}

TEST(builder_test, full_uri_has_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).path());
}

TEST(builder_test, full_uri_path_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("/path", *network::uri(builder).path());
}

TEST(builder_test, full_uri_has_query) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).query());
}

TEST(builder_test, full_uri_query_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("query", *network::uri(builder).query());
}

TEST(builder_test, full_uri_has_fragment) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_TRUE(network::uri(builder).fragment());
}

TEST(builder_test, full_uri_fragment_value) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .user_info("user:password")
    .host("www.example.com")
    .port("80")
    .path("/path")
    .query("query")
    .fragment("fragment")
    ;
  ASSERT_EQ("fragment", *network::uri(builder).fragment());
}

TEST(builder_test, relative_uri) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("www.example.com/", network::uri(builder));
}

TEST(builder_test, relative_uri_scheme) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_FALSE(network::uri(builder).scheme());
}

TEST(builder_test, relative_uri_has_host) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_TRUE(network::uri(builder).host());
}

TEST(builder_test, relative_uri_host_value) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("www.example.com", *network::uri(builder).host());
}

TEST(builder_test, relative_uri_has_path) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_TRUE(network::uri(builder).path());
}

TEST(builder_test, relative_uri_path_value) {
  network::uri_builder builder;
  builder
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("/", *network::uri(builder).path());
}

TEST(builder_test, build_uri_with_capital_scheme) {
  network::uri_builder builder;
  builder
    .scheme("HTTP")
    .host("www.example.com")
    .path("/")
    ;
  ASSERT_EQ("http://www.example.com/", network::uri(builder));
}

TEST(builder_test, build_uri_with_capital_host) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("WWW.EXAMPLE.COM")
    .path("/")
    ;
  ASSERT_EQ("http://www.example.com/", network::uri(builder));
}

TEST(builder_test, build_uri_with_unencoded_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/A path with spaces")
    ;
  ASSERT_EQ("http://www.example.com/A%20path%20with%20spaces", network::uri(builder));
}

TEST(builder_test, DISABLED_builder_uri_and_remove_dot_segments_from_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/A/./path/")
    ;
  ASSERT_EQ("http://www.example.com/A/path/", network::uri(builder));
}

TEST(builder_test, build_uri_with_qmark_in_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/?/")
    ;
  ASSERT_EQ("http://www.example.com/%3F/", network::uri(builder));
}

TEST(builder_test, build_uri_with_hash_in_path) {
  network::uri_builder builder;
  builder
    .scheme("http")
    .host("www.example.com")
    .path("/#/")
    ;
  ASSERT_EQ("http://www.example.com/%23/", network::uri(builder));
}

//TEST(builder_test, simple_port) {
//  network::uri_builder builder;
//  builder
//    .scheme("http")
//    .host("www.example.com")
//    .port(8000)
//    .path("/")
//    ;
//  ASSERT_EQ("http://www.example.com:8000/", builder.uri().string());
//}

//TEST(builder_test, simple_port_us) {
//  network::uri_builder builder;
//  builder
//    .scheme("http")
//    .host("www.example.com")
//    .port(unsigned short(8000))
//    .path("/")
//    ;
//  ASSERT_EQ("http://www.example.com:8000/", builder.uri().string());
//}
//
//
//BOOST_AUTO_TEST_CASE(query_test) {
//  network::uri instance;
//  network::builder builder(instance);
//  builder
//     .scheme("http")
//     .host("www.example.com")
//     .path("/")
//     .query("key", "value")
//    ;
//  BOOST_REQUIRE(network::valid(instance));
//  BOOST_CHECK_EQUAL("http://www.example.com/?key=value", instance.string());
//}
//
//BOOST_AUTO_TEST_CASE(query_2_test) {
//  network::uri instance;
//  network::builder builder(instance);
//  builder
//     .scheme("http")
//     .host("www.example.com")
//     .path("/")
//     .query("key1", "value1")
//     .query("key2", "value2")
//    ;
//  BOOST_REQUIRE(network::valid(instance));
//  BOOST_CHECK_EQUAL("http://www.example.com/?key1=value1&key2=value2", instance.string());
//}
//
//BOOST_AUTO_TEST_CASE(fragment_test) {
//  network::uri instance;
//  network::builder builder(instance);
//  builder
//     .scheme("http")
//     .host("www.example.com")
//     .path("/")
//     .fragment("fragment")
//    ;
//  BOOST_REQUIRE(network::valid(instance));
//  BOOST_CHECK_EQUAL("http://www.example.com/#fragment", instance.string());
//}
//
//BOOST_AUTO_TEST_CASE(ipv4_address) {
//  using namespace boost::asio::ip;
//  network::uri instance;
//  network::builder builder(instance);
//  builder
//    .scheme("http")
//    .host(address_v4::loopback())
//    .path("/")
//    ;
//  BOOST_REQUIRE(network::valid(instance));
//  BOOST_CHECK_EQUAL("http://127.0.0.1/", instance.string());
//}
//
//BOOST_AUTO_TEST_CASE(ipv6_address) {
//  using namespace boost::asio::ip;
//  network::uri instance;
//  network::builder builder(instance);
//  builder
//    .scheme("http")
//    .host(address_v6::loopback())
//    .path("/")
//    ;
//  BOOST_REQUIRE(network::valid(instance));
//  BOOST_CHECK_EQUAL("http://[::1]/", instance.string());
//}

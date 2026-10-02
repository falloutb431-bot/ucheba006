#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "list.hpp"

TEST_CASE("Empty returns true for newly created list", "[list][empty]") {
    List lst;
    REQUIRE(lst.Empty() == true);
    REQUIRE(lst.Size() == 0);
}

TEST_CASE("Size reflects number of elements", "[list][size]") {
    List lst;

    REQUIRE(lst.Size() == 0);

    lst.PushFront(10);
    REQUIRE(lst.Size() == 1);

    lst.PushBack(20);
    REQUIRE(lst.Size() == 2);

    lst.PushFront(30);
    REQUIRE(lst.Size() == 3);
}

TEST_CASE("Clear empties the list and resets size", "[list][clear]") {
    List lst;
    lst.PushFront(1);
    lst.PushBack(2);
    lst.PushFront(3);

    REQUIRE(lst.Size() == 3);
    REQUIRE(lst.Empty() == false);

    lst.Clear();

    REQUIRE(lst.Size() == 0);
    REQUIRE(lst.Empty() == true);

    lst.PushBack(42);
    REQUIRE(lst.Size() == 1);
    REQUIRE(lst.Empty() == false);
}
#include <iterator>

import Module;

static_assert(std::same_as<int, std::iter_value_t<ns::Bar<int>>>);

int main()
{
}


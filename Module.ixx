module;

#include <iterator>

export module Module;

export struct Foo {};

export namespace ns
{
	template<typename T> struct Bar {};

}
export template <typename T>
struct std::iterator_traits<ns::Bar<T>>
{
	using difference_type = std::ptrdiff_t;
	using size_type = std::size_t;

	using value_type = int;
	using pointer = value_type*;
	using reference = value_type&;
	using iterator_category = std::random_access_iterator_tag;
};


// if an unrelated full specialization is exported in the same module,
// it will work just fine!
// Uncomment the following lines to check it out:

//export template <>
//struct std::iterator_traits<Foo>
//{
//	using difference_type = std::ptrdiff_t;
//	using size_type = std::size_t;
//
//	using value_type = int;
//	using pointer = value_type*;
//	using reference = value_type&;
//	using iterator_category = std::random_access_iterator_tag;
//};

static_assert(std::same_as<int, std::iter_value_t<ns::Bar<int>>>);
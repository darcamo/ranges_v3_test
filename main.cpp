#include <iostream>
#include <range/v3/all.hpp>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace ranges;

int multiplyBy2(int a) { return 2 * a; }

bool isEven(int a) { return a % 2 == 0; }
bool isOdd(int a) { return !isEven(a); }

int main(int /*argc*/, char** /*argv*/)
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    auto range = numbers | view::transform(multiplyBy2);

    // copy(range, std::ostream_iterator<std::string>(std::cout));
    // auto lala = std::ostream_iterator<std::string>(std::cout, ", ");

    copy(numbers | view::transform(multiplyBy2) | view::take(3), ranges::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\n";
    std::cout << ranges::accumulate(numbers | view::transform(multiplyBy2), 0) << std::endl;
    std::cout << ranges::accumulate(numbers | view::filter(isOdd) | view::transform(multiplyBy2), 0) << std::endl;

    std::vector<int> vi =
        view::for_each(view::ints(1,10), [](int i){
                                             return yield_from(view::repeat_n(i,i/2 + 1));
                                         });
    copy(vi, ranges::ostream_iterator<int>(std::cout, ", "));
    return 0;
}

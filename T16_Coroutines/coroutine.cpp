#include <iostream>
#include <coroutine>

void call_coroutine();
//void run_generator();

int main() {
    call_coroutine();
    //run_generator();
}

struct ReturnObject {
  struct promise_type {
    unsigned value_;

    ReturnObject get_return_object() { 
        return {.h_ = std::coroutine_handle<promise_type>::from_promise(*this)};
    }
    void unhandled_exception() noexcept {}
    void return_void() noexcept {}        
    std::suspend_never initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }

    std::suspend_always yield_value(unsigned value) {
      value_ = value;
      return {};
    }

  };
  std::coroutine_handle<promise_type> h_;
};

auto my_coroutine() -> ReturnObject {
  for (auto i = 0; i < 3; ++i) {
    co_yield i; // yields 3 values the stops
  }
}

void call_coroutine() {
  auto h = my_coroutine().h_; // The state-object handle
  auto &promise = h.promise(); // The container for the results

  while (!h.done()) {
    std::cout << "Next value: " << promise.value_ << std::endl;
    h(); // resume the co-routine.
  }
  h.destroy(); // Free up the heap-based state-object
}

//#include <generator>
//#include <ranges>
// 
//std::generator<int> fib() {
//    co_yield 0;                    // (1)
//    auto a = 0;
//    auto b = 1;
//    for(auto n : std::views::iota(0)) {  
//        auto next = a + b;
//        a = b;
//        b = next;
//        co_yield next;            // (2)   
//    }
//}
//
//void run_generator() {
//    for (auto f : fib() | std::views::take(10)) {
//        std::cout << f << " ";
//    }
//}
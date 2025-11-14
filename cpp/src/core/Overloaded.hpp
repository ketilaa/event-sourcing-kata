#pragma once

template<class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

// deduction guide
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

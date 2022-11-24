#ifndef GEODE_CORE_META_DEFAULTCONV_HPP
#define GEODE_CORE_META_DEFAULTCONV_HPP

namespace geode::core::meta {
    template <class Ret, class... Args>
    class DefaultConv {
    public:
        static Ret invoke(void* address, Args... all) {
            Ret (*raw)(Args...) = reinterpret_cast<decltype(raw)>(address);
            return raw(all...);
        }

        template <Ret (*detour)(Args...)>
        static auto get_wrapper() {
            return reinterpret_cast<void*>(detour);
        }
    };
}

#endif /* GEODE_CORE_META_DEFAULTCONV_HPP */

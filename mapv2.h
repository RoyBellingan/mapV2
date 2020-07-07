#include <map>

template <typename K, typename V>
class map2 : public std::map<K, V> {
      public:
	[[nodiscard]] auto get(const K& k) const {
		struct Founded {
			const V val;
			bool    found = false;
			operator bool() {
				return found;
			}
		};

		if (auto iter = this->find(k); iter != this->end()) {
			return Founded{iter->second, true};
		} else {
			return Founded{};
		}
	}
};

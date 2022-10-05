#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
  int size;
  list<pair<int, int>> lru_list; // 紀錄當前輸入的資料，並依據 `size` 調整資料
  unordered_map<int, list<pair<int, int>>::iterator>
      cache_map; // 紀錄 {key: (key, value)} 歷史資料

  LRUCache(int capacity, ...) { size = capacity; }

  int get(int key) {
    // 找不到則回傳 -1
    if (cache_map.find(key) == cache_map.end()) {
      return -1;
    }

    lru_list.splice(lru_list.begin(), lru_list, cache_map[key]);
    return cache_map[key]->second;
  }

  void put(int key, int value) {
    // 將數值加入 `lru_list` 中
    if (cache_map.find(key) != cache_map.end()) {
      lru_list.splice(lru_list.begin(), lru_list, cache_map[key]);
      lru_list.begin()->second = value;
      return;
    }

    // 若當前 `lru_list` 是滿的情況
    if (lru_list.size() == size) {
      cache_map.erase(
          lru_list.back().first); // `cache_map` 會將最後一筆加入`lru_list`
                                  // 的元素 `key` 移除
      lru_list.pop_back(); // `lru_list` 再將最後一筆元素移除
    }

    lru_list.emplace_front(
        make_pair(key, value)); // 將近期加入的元素推入 `lru_list` 第一位
    cache_map[key] = lru_list.begin(); // 紀錄加入元素的鍵值比對
  }
};

int main(int argc, char *argv[]) {

  LRUCache *lru = new LRUCache(2);

  lru->put(1, 1);
  cout << "加入(1, 1) 後 lru_list 大小：\t" << lru->lru_list.size() << endl;
  lru->put(2, 2);
  cout << "加入(2, 2) 後 lru_list 大小：\t" << lru->lru_list.size() << endl;
  cout << "取得 key 為 1 的 value：\t" << lru->get(1) << endl;
  lru->put(3, 3);
  cout << "加入(3, 3) 後 lru_list 大小：\t" << lru->lru_list.size() << endl;

  return 0;
}

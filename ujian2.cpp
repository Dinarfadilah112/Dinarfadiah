#include <iostream>
#include <unordered_map>

void findPairs(int arr1[], int n1, int arr2[], int n2, int K) {
  std::unordered_map<int, int> map;

  // Simpan elemen array pertama ke dalam map
  for (int i = 0; i < n1; i++) {
    map[arr1[i]] = i;
  }

  // Iterasi array kedua dan cari pasangan yang jumlahnya sama dengan K
  for (int i = 0; i < n2; i++) {
    int target = K - arr2[i];
    if (map.find(target) != map.end()) {
      std::cout << "Pasangan (" << arr1[map[target]] << ", " << arr2[i] << ")" << std::endl;
    }
  }
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {6, 7, 8, 9, 10};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  int K = 9;

  findPairs(arr1, n1, arr2, n2, K);

  return 0;
}
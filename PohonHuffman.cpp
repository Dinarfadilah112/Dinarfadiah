#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <queue>
#include <unordered_map>
#include <string>

// Struktur node pohon Huffman
struct Node {
    char karakter;
    int frekuensi;
    Node* kiri;
    Node* kanan;
};

// Fungsi untuk membangun pohon Huffman
Node* buildHuffmanTree(const std::string& input) {
    // Buat tabel frekuensi karakter
    std::unordered_map<char, int> frekuensi;
    for (char c : input) {
        frekuensi[c]++;
    }

    // Buat antrian prioritas untuk node-node pohon Huffman
    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> antrian(
        [](Node* a, Node* b) { return a->frekuensi > b->frekuensi; });

    // Tambahkan node-node ke antrian
    for (const auto& pair : frekuensi) {
        Node* node = new Node{pair.first, pair.second, nullptr, nullptr};
        antrian.push(node);
    }

    // Bangun pohon Huffman
    while (antrian.size() > 1) {
        Node* node1 = antrian.top();
        antrian.pop();
        Node* node2 = antrian.top();
        antrian.pop();

        Node* newNode = new Node{'\0', node1->frekuensi + node2->frekuensi, node1, node2};
        antrian.push(newNode);
    }

    return antrian.top();
}

// Fungsi untuk melakukan encoding Huffman
std::string encodeHuffman(const std::string& input, Node* root) {
    std::unordered_map<char, std::string> kode;
    std::function<void(Node*, std::string)> traverse = [&](Node* node, std::string kodeSementara) {
        if (node->kiri == nullptr && node->kanan == nullptr) {
            kode[node->karakter] = kodeSementara;
        } else {
            traverse(node->kiri, kodeSementara + "0");
            traverse(node->kanan, kodeSementara + "1");
        }
    };

    traverse(root, "");

    std::string encoded;
    for (char c : input) {
        encoded += kode[c];
    }

    return encoded;
}

// Fungsi untuk melakukan decoding Huffman
std::string decodeHuffman(const std::string& encoded, Node* root) {
    std::string decoded;
    Node* currentNode = root;

    for (char c : encoded) {
        if (c == '0') {
            currentNode = currentNode->kiri;
        } else {
            currentNode = currentNode->kanan;
        }

        if (currentNode->kiri == nullptr && currentNode->kanan == nullptr) {
            decoded += currentNode->karakter;
            currentNode = root;
        }
    }

    return decoded;
}

int main() {
    cout << "Nama : Dinar Fadilah" << endl;
    cout << "NIM : 231011401202" << endl;
    cout << "Kelas : 03TPLP029" << endl << endl;
    
    std::string input;
    std::cout << "Masukkan string: ";
    std::cin >> input;

    Node* root = buildHuffmanTree(input);
    std::string encoded = encodeHuffman(input, root);
    std::string decoded = decodeHuffman(encoded, root);

    std::cout << "String asli: " << input << std::endl;
    std::cout << "String terkompresi: " << encoded << std::endl;
    std::cout << "String dekompresi: " << decoded << std::endl;

    return 0;
}

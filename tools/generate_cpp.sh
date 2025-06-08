#!/bin/bash

FILENAME=$1

# 파일 경로
CPP_FILE="푸는중/${FILENAME}.cpp"

cat > "$CPP_FILE" <<EOF
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    return 0;
}
EOF

echo "[✔] 생성 완료 → $CPP_FILE"
code "$CPP_FILE"

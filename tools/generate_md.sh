#!/bin/bash

FILEPATH=$1
FILENAME=$(basename "$FILEPATH" .cpp)
DIRNAME=$(basename "$(dirname "$FILEPATH")")

if [[ "$DIRNAME" != "푸는중" ]]; then
  echo "[🚫] 이 스크립트는 '푸는중/' 폴더의 파일에서만 실행할 수 있습니다."
  exit 1
fi
EXT="cpp"
TODAY=$(date +%y-%m-%d)
DEST_DIR="완료/$TODAY"
MD_FILE="$DEST_DIR/${FILENAME}.md"

SRC_CPP_FILE="푸는중/${FILENAME}.${EXT}"
SRC_EXEC_FILE="푸는중/${FILENAME}"

# 파일 확인
[ ! -f "$SRC_CPP_FILE" ] && echo "[X] ${SRC_CPP_FILE} 파일이 존재하지 않음!" && exit 1

# 완료 폴더 생성
mkdir -p "$DEST_DIR"

if [ -f "$MD_FILE" ]; then
  echo "[⚠️] 이미 존재하는 마크다운 파일입니다: $MD_FILE"
  echo "👉 덮어쓰지 않고 스크립트를 종료합니다."
  exit 0
fi

# cpp 파일 이동
mv "$SRC_CPP_FILE" "$DEST_DIR/"

# 실행 파일 삭제
if [ -f "$SRC_EXEC_FILE" ]; then
  rm "$SRC_EXEC_FILE"
  echo "[🗑] 실행 파일 삭제됨: ${SRC_EXEC_FILE}"
fi

NEW_CPP_FILE="$DEST_DIR/${FILENAME}.${EXT}"

# 마크다운 생성
cat > "$MD_FILE" <<EOF
# ${FILENAME}번: 

## 문제 요약
### 문제


### 사용 알고리즘


### 입출력
- 입력: 
- 출력: 
\`\`\`
예제1

입력

출력

\`\`\`
## 풀이


## 어려웠던 점


## 배운 점 / 느낀 점


## 전체 코드
\`\`\`cpp
$(cat "$NEW_CPP_FILE")
\`\`\`
EOF

echo "[✔] 완료/$TODAY/ 이동 및 마크다운 생성 완료: ${MD_FILE}"

# ✅ VSCode에서 마크다운 파일 열기
code "$MD_FILE"

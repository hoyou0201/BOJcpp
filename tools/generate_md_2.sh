#!/bin/bash

# 인자로 받은 cpp 파일 경로
FILEPATH=$1

# 파일명 추출 (확장자 제거)
FILENAME=$(basename "$FILEPATH" .cpp)
DIR=$(dirname "$FILEPATH")
MD_FILE="${DIR}/${FILENAME}.md"
CPP_FILE="${DIR}/${FILENAME}.cpp"

# 존재 확인
if [ ! -f "$CPP_FILE" ]; then
  echo "[❌] ${CPP_FILE} 파일이 존재하지 않습니다."
  exit 1
fi

# 이미 마크다운 존재할 경우
if [ -f "$MD_FILE" ]; then
  echo "[⚠️] 이미 마크다운 파일이 존재합니다: ${MD_FILE}"
  echo "👉 덮어쓰지 않고 종료합니다."
  exit 0
fi

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
$(cat "$CPP_FILE")
\`\`\`
EOF

echo "[✔] 마크다운 생성 완료: ${MD_FILE}"
code "$MD_FILE"

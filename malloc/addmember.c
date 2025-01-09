#include "list.h"

void add_member(MEMBER **head, MEMBER *newmem) {
    // 맨 앞에 삽입
    newmem->m_next = *head;
    *head = newmem;
}
# MyLib Project (CSE4100: System Programming)

<br/>

## **📌 프로젝트 개요**
- MyLib 프로젝트에서는 **리스트(List)**, **해시 테이블(Hash Table)**, **비트맵(Bitmap)** 의 기능을 구현하고, 이를 테스트하는 **인터랙티브 프로그램**을 개발.
- 본 프로젝트는 시스템 프로그래밍의 기초가 되는 **자료구조 활용 및 구현 능력**을 향상하는 것이 목표.

<br/>

## **📌 프로젝트 수행 상세 내용**

### **1. 리스트(List) 구현**
>📌 **구현 개요**
>- **이중 연결 리스트 (Doubly Linked List)** 기반 구현
>
>📌 **구현 기능**
>- `list_swap()` : 리스트 내 두 요소 교환
>- `list_shuffle()` : 리스트 요소 섞기

<br/>

### **2. 해시 테이블(Hash Table) 구현**
>📌 **구현 개요**
>- **연결 리스트 기반 해시 테이블** 구현
>- 해시 함수(`hash_int()`) 활용
>
>📌 **구현 기능**
>- `hash_int_2()` : 정수 해싱값 반환

<br/>

### **3. 비트맵(Bitmap) 구현**
>📌 **구현 개요**
>- **비트 배열(Bit Array)** 을 사용하여 불리언 값 저장
>- 메모리 절약을 위한 효율적인 자료구조 구현
>
>📌 **구현 기능**
>- `bitmap_expand`() : 비트맵 길이 확장

<br/>

### **4. 인터랙티브 프로그램 구현**
>📌 **구현 개요**
>- 표준 입력(STDIN)에서 명령을 읽어 **리스트, 해시 테이블, 비트맵을 조작**
>- 다음 명령어를 지원
>
>📌 **지원 명령어 예시**
>```sh
>create list <LIST>
>create hashtable <HASH TABLE>
>create bitmap <BITMAP> <BIT CNT>
>delete <LIST | HASH TABLE | BITMAP>
>dumpdata <LIST | HASH TABLE | BITMAP>
>quit

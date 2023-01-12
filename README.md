## 자료구조 및 알고리즘 공부
개요 : 코드에 대한 복습 및 공부용.

### Linked List
![저장](https://user-images.githubusercontent.com/93506849/198925568-e8d42ee6-1757-4ead-851a-a4c5c2adf954.JPG)
- Node의 다음 포인터가 다음 Node를 가리키는 구조로써 배열처럼 연속되는 메모리에 저장하는 방식이 아니어서 Node사이에 새로운 정보를 끼워 넣기 용이한 구조

### Doubly Linked List
![저장용](https://user-images.githubusercontent.com/93506849/199155334-3b8d496b-95ea-4dc4-b1bf-edc94da775e8.JPG)
- 단방향 연결 리스트는 다음 노드의 탐색만 가능했던 것에 비해서 이중 연결 리스트의 경우 앞뒤로 탐색이 가능합니다. 상황에 따라 탐색의 방향이 바뀌어야 하는 경우라면 이중 연결 리스트를 사용합니다.
- 단점으로는 단방향 연결 리스트에 비해 메모리를 더 소모한다.
### Stack
![스택택](https://user-images.githubusercontent.com/93506849/199390754-73387262-aaba-4a42-8291-3a1da4e94db2.JPG)
- 배열/연결리스트로 구현이 가능, 함수의 지역 변수 혹은 돌아갈 주소에 사용할 때 Stack frame을 사용한다. 함수들은 전부 Stack을 사용하며, 재귀함수를 추적할 때 Stack이 적합하다. 입력된 자료의 순서를 뒤집을 때 사용.
### Queue
![Queue](https://user-images.githubusercontent.com/93506849/200154570-593a84e9-33cb-4c5b-9326-ed0ea0cb9c55.JPG)
- Circular Queue/ Linked List Queue로 구현이 가능, 1차원적인 선입 선출의 구조로 앞순서 부터 먼저처리해야 할때 주로 사용된다.(Window Procedure의 Message Queue)
### Left Child Right Sibling Tree
![트리구조도](https://user-images.githubusercontent.com/93506849/200729978-5a944179-6f44-4105-900e-4f8421b65331.JPG)
- 탐색 트리 중 가장 기초적인 형태의 트리 구조이다. 좌측에 자식 클래스, 우측에는 형제 노드를 연결 시킨다.
- 검색엔진, DBMS, 라우터 등 계층적 데이터를 다루는 곳에 사용된다.

### Binary Tree
![이진트리 탐색](https://user-images.githubusercontent.com/93506849/201507553-7197c341-cd5c-44ad-ab5c-c23f7e573483.JPG)
- 탐색 트리 중 기본적으로 쓰이는 트리이다. 데이터당 자식을 두개 밖에 못가지며, 재귀함수 사용을 중점에 둔다.
- 효율적인 검색과 정렬을 위해 사용된다.

### Set
- Set형태의 자료구조는 List와 Map의 사이의 개념 정도의 자료구조입니다.\
-List 데이터를 순서대로 저장하는 자료구조 (값의 중복은 허용됨)\
-Map 데이터를 Key 와 Value의 형태로 저장하는 자료구조 (Key의 중복은 허용되지 않음)

- Set은 기본적으로 순서대로 데이터를 저장하지 않습니다. 하지만 List의 형태와는 달리 값의 중복을 허용하지 않습니다.\
-Set은 중복값을 삽입할 수 없다.\
-Set은 기본적으로 특정한 순서대로 데이터를 저장하지 않는다.

### Map
ist형태의 자료구조들은 순서대로 값을 차곡차곡 집어넣는 일련의 하나의 줄과 같은 형태입니다.
- 반면 Map 형태의 자료구조는 각각의 Key와 매칭 되는 Value들이 존재합니다. 
- 즉 순서보다는 정의된 이름(Key)과 상응하는 데이터들을 묶기 위한 자료 구조로서 효과적입니다.


#### Map 자료구조의 대표적인 종류
- HashMap\
key와 value의 쌍으로만 구성이 될뿐 자료구조 안에 묶인 쌍들에 대한 순서는 보장할 수 없다.\
즉, 사용자는 키와 값이 구성되는 위치를 결정 하거나 알 수 없다.
- TreeMap\
key의 값을 이용해 순서대로 정렬하여 데이터를 저장하는 자료구조\
key값을 통한 탐색 뿐 아니라 key값의 정렬을 통한 탐색 등을 하기에 용의 하다.
- LinkedHashMap\
데이터를 입력한 순서대로 쌓아지며 데이터를 저장하는 자료구조\
배열, 리스트처럼 인덱싱 접근을 하기에 용의 하다.

### Hesh

## 코딩 테스트 관련+유니티 기술
### 유니티 최적화!!
![최적화 주요사항](https://user-images.githubusercontent.com/93506849/208405807-aca10d87-a424-4a0f-8a20-1f90eae44560.JPG)
### 유니티 오클루전컬링& 뷰 프러스텀 컬링!!!!
![109426546-98c58600-7a31-11eb-9b64-752e0d63a804](https://user-images.githubusercontent.com/93506849/208408803-c4909b95-b877-4d0e-a66f-af93a0f7242c.gif)
### 유니티 호출 순서!!!
![monobehaviour_flowchart](https://user-images.githubusercontent.com/93506849/208405854-e93e50bf-7f89-4405-831b-6c276c93e9bb.svg)

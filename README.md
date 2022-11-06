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
- Circular Queue/ Linked List Queue로 구현이 가능, 1차원적인 선입 선출의 구조로 앞순서 부터 먼저처리해야 할때 주로 사용된다.(Window Procedure)

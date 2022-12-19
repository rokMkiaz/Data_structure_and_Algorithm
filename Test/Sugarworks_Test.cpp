/*
1. Delegate, event
Delegate : 델리게이트는 한마디로 말해서 대리자라고 말할 수 있습니다. 
           즉, 대신 일을 해주는 녀석이라고 할 수 있겠죠? 다른 말로 해서는 메소드 
           참조를 포함하고 있는 영역이라고 말할 수 있습니다. 아래는 델리게이트의 선언 형식입니다.
          ex)- delegate 반환형 델리게이트명(매개변수..);
event   :  '특정 사건이 벌어지면 알리는 메시지'라고 할 수 있습니다. 
            이벤트를 예로 들자면, 사용자가 컨트롤(버튼, 이미지, 레이블, 텍스트박스 등..)을 클릭하거나
            창을 닫거나 열때 사용자에게 개체를 알리는 것을 이벤트 발생이라고 합니다. 
            C#에서는 우리가 방금 배운 델리게이트를 사용하여 이벤트를 처리할 수 있습니다. 
            이벤트의 기본적인 선언 형식은 다음과 같습니다.
          ex)- 한정자 event 델리게이트 이름;

delegate 반환형 델리게이트명(매개변수..);
2. foreach
        - 끝을 지정해주는 다른 반복문과 달리,
        인자로 들어온 itrable-item의 내부 인덱스 끝까지 알아서 순환을 해주는 반복문 입니다.
        Cpp에서는 for(auto a : A)형식으로 배열부르는 것과 비슷하다.
        ex)
           //foreach문
            Console.WriteLine("## foreach 사용");
            int index = 0;
            foreach(int elem in arr)
            {
                Console.WriteLine("arr[" + index + "] : " +elem);
                ++index;
            }
            Console.WriteLine("current i : " + index);
        
            //for문으로 작성했다면?
            Console.WriteLine();
            Console.WriteLine("## for 사용");
            for(int i=0; i<7; ++i)
            {
                Console.WriteLine("arr[" + i + "] : " + arr[i]);
            }

 3. 람다식 표현
     // 입력 파라미터가 없는 경우
    () => Write("No");
    
    // 입력 파라미터가 1~2개 있는 경우
    (p) => Write(p);
    (s, e) => { Write(s); Write(e); }
    
    // 입력 파라미터 타입을 명시하는 경우
    (string s, int i) => Write(s, i);

4. vector, list, map 차이
    - vector
    데이터가 순차적으로 저장 되므로 검색속도가 빠르지 않음
    데이터의 위치를 안다면 배열처럼 쉽게 접근 가능
    
    - list
    리스트는 vector의 단점인 중간값 삽입 삭제가 가능하게 만들어 졌습니다.
    포인터로 다음 값을 찾아주는 방식이므로 모든 삽입 삭제가 용이함.
    단점으로는 vector에서 가능했던 데이터의 위치로 값에 접근할 수 없음.
    또한 순차 접근이라 검색도 느림.
    
    - map
    트리구조임
    맵은 자동 정렬이 됨
    검색속도가 일렬 방식(list, vector)보다 빠름
    단점으로는 삽입 삭제가 빈번하면 안됨!!!(할때마다 정렬하고 있음.)

5. 벡터를 이용한 방향 측정
    벡터의 외적은 벡터 곱이라 할 수 있으며, 벡터 A와 벡터 B의 외적을 A x B라고 한다 [A cross B]. 
    외적의 결과는 내적과 달리 벡터가 나오며, A x B [외적 벡터]의 방향은 수학에서는 오른손 법칙을 사용한다.
    게임은 엔진이 사용하는 좌표계에 따라 다른데, OpenGL에서는 오른손 법칙, Unity는 왼손 법칙에 따른다. 
    그리고 외적 벡터의 크기는 두 벡터의 크기에 sinθ를 곱한 값과 같다. [A x B = |A| |B| sin θ] 
    외적의 특징으로 A와 B 벡터의 외적, AxB는 벡터 A와도 수직이고, 벡터 B와도 수직이다
    
    캐릭터와 적이 월드 상에 존재할 때 월드 좌표계의 Up 방향 벡터를 U, 캐릭터의 Forward 방향 벡터를 F,
    그리고 적과 캐릭터의 위치를 뺀 벡터를 A라고 할 때, 적이 왼쪽에 있는지 오른쪽에 있는지 판별은 Up ·
    (F x A) 를 해서 0보다 크면 오른쪽 0보다 작으면 왼쪽에 존재한다. 먼저 (F x A)를 보자면 캐릭터의 
    앞 방향 벡터와 캐릭터에서 적을 향하는 벡터를 외적을 하면 두 벡터의 수직인 벡터 F x A 가 나온다.
    이 벡터가 월드 좌표계의 Up 방향 벡터와 내적을 하면 나오는 값이 0보다 크다면 예각을 이루고, 
    0보다 작다면 둔각을 이루기 때문에 왼쪽 오른쪽 판별을 할 수 있습니다.

6. 코루틴과 Invoke
    코루틴 : 협력형 멀티 태스킹, 동시성 프로그래밍 지원, 비동기 처리 쉽게도와줌.멀티쓰레드 기능을 통해 동시
    작업을할 수있게 지원해 준다
    Invoke : 멀티스레드 환경에서 데이터 보호를 위해 사용.이름없이 호출됨 -> 람다식 처럼 사용됨.

7. 오클루전 컬링과 뷰 프러스텀(View frustom) 컬링
    오클루전 컬링 : 오클루전 컬링은 Unity가 다른 게임 오브젝트에 의해 뷰에서 완전히 가려진(오클루전된) 
                   게임 오브젝트에 대한 렌더링 계산을 수행하지 못하도록 하는 프로세스입니다.
    프러스텀 컬링 : 우리가 카메라로 보고있는 영역 즉 절두체 밖의 오브젝트는 그리지 않고 절두체 
                   내부에 있는 오브젝트들만 그리는 것인데, 이 절두체는 근평면, 원평면, 상평면,하평면, 좌평면, 우평면으로
                   총 6개의 평면으로 이루어져 있다.평면은 점 1개와 법선벡터 1개 혹은 점 3개 등의 방법으로 표현이 
                   가능한데, 그 중 점 1개와 법선벡터를 이용한 평면으로 프러스텀 컬링을 설명해 보겠다.
*/
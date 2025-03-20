#include <iostream>
#include <memory>
#include <cmath>

using namespace std;

int main()
{
    int64_t N;
    cin >> N;

    // N == 0 case
    if (N == 0)
    {
        cout << "NO";
        return 0;
    }

    // 입력받은 수보다 작은 3의 거듭제곱 중에서 가장 큰값의 지수
    int64_t numerical_index = -1;
    for (int64_t i = 1; i <= N; i *= 3)
    {
        numerical_index++;
    }

    // 삼삼한 수인지 N에서 3의 거듭제곱을 빼서 확인
    while (numerical_index + 1)
    {
        if (N >= pow(3, numerical_index))
            N -= pow(3, numerical_index);
        numerical_index--;
    }

    if (!N)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
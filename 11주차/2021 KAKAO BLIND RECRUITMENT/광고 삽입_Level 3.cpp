#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

// ���� ����� ��� �ؾ��ұ�?

// ������ ��� ������ �����̵�(= ���� �����̵�)�� �����Ǿ� �ִ�.
// �� ��û�ڵ��� ��� ������ �����̵嵵 �����Ǿ� �ִ�.

// ��û���� ��� ���� �����̵� = int�� vector�� ����, vector�� �� index�� ���� 1��. (begin => ��û ���� �ð�, end => ��û ���� �ð�)
// ���� ���� int�� vector(��û�� ��� ���� �����̵�)�� �ϳ��� vector�� ��ģ��. (begin => 0, end => 3600000)
//      -> ������ ��� ������ ���� 99:59:59�� �ִ�, -> 100:00:00 - 00:00:01 -> 100 * 3600 - 1 = 359999
// ���� �����̵�(0 - ���� ��� �ð�)�� ���Ϳ� ���� �� ���Ѵٰ� ����. (�� ���븦 ���ִ��ٰ� ����.)
// 0���� �����Ͽ�, vector�� ������ ��.
// ���� �����̵� ���� ���� vector�� index�� �� �������� ������ Max���� ���� ����ð��� ���� ���� ��.

// if vector�� size = 8, [1, 1, 2, 2, 3, 3, 1, 1], ���� �����̵��� ���� = 2��� �Ͽ��� ��,
//      [0, 1] = 2 / [1, 2] = 3 / [2, 3] = 4 / [3, 4] = 5 / [4, 5] = 6 / [5, 6] = 4 / [6, 7] = 2.
//      [4, 5]�� ���� ���� ũ��. �� �� ���� ���� ����ð��� ���� ���� ���̴�.

int time_to_int(string a)
{
    int hour = stoi(a.substr(0, 2));
    int min = stoi(a.substr(3, 2));
    int sec = stoi(a.substr(6, 2));

    return (hour * 3600) + (min * 60) + sec;
}

string time_to_string(int a)
{
    cout << a << '\n';
    int hour = a / 3600;
    a = a % 3600;
    int min = a / 60;
    int sec = a % 60;

    stringstream ss;
    ss << std::setfill('0') << std::setw(2) << to_string(hour) << ":" << std::setw(2) << to_string(min) << ":" << std::setw(2) << to_string(sec);
    return ss.str();
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int time = 0;

    vector<int> sum(360001, 0);

    int p_time = time_to_int(play_time);
    int a_time = time_to_int(adv_time);

    if (play_time == adv_time)
    {
        return "00:00:00";
    }

    for (auto log : logs)
    {
        int start_time = time_to_int(log.substr(0, 8));
        int end_time = time_to_int(log.substr(9, 8));

        // �� ��û���� ��û ���� �ð�����,
        // ��û �� �ð������� ������ +1�� ǥ����.
        // -> ���� ��û ����
        // ���������� �� ��û�ڵ��� ���� ���� ��ġ�� ������ ǥ����.

        for (int i = start_time; i < end_time; i++)
        {
            sum[i]++;
        }

    }

    long long adv_sum = 0;
    long long adv_max_sum = 0;

    // 0����, adv - 1 ������ ���� ��û ������ ����
    // �� -1? -> �ð� ����, 1�� ���� �����
    // 1�ʺ��� 10�� -> 9�ʷ� ���

    for (int i = 0; i < a_time; i++)
    {
        adv_sum += sum[i];
    }

    adv_max_sum = adv_sum;

    // 0 ���� adv - 1 ������ ���� ��û ������
    // 1 ���� adv ������ ���� ��û ������ ���ϸ鼭, �ִ��� ��������� ����.
    // 1�� �÷���.
    // +1�� ���� -> 1�� ���� ����� ���� ������.

    for (int i = a_time; i < p_time; i++)
    {
        adv_sum -= sum[i - a_time];
        adv_sum += sum[i];

        if (adv_sum > adv_max_sum)
        {
            adv_max_sum = adv_sum;
            time = i - a_time + 1;
        }
    }

    answer = time_to_string(time);
    return answer;
}
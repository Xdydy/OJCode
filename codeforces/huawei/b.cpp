#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.
struct Machine {
    int over_time;
    bool can_use;
    int width;
    bool operator<(const Machine &b) const { return width > b.width; }
};
struct Task {
    int task_width;
    int task_time;
    Task(int a, int b) {
        task_width = a;
        task_time = b;
    }
    bool operator<(const Task &b) const { return task_width < b.task_width; }
};
priority_queue<Task> Q_tasks;
vector<Task> V_tasks;
vector<int> V_machine_can_use;
Machine machines[1010];
int task_width[10010];
int task_time[10010];
int m, n;
int main() {
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    while (cin >> m >> n) {
        //输入机器
        for (int i = 0; i < n; i++) {
            cin >> machines[i].width;
            machines[i].can_use = true;
        }
        //输入任务
        for (int i = 0; i < m; i++) {
            cin >> task_width[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> task_time[i];
            Q_tasks.push(Task(task_width[i], task_time[i]));
        }
        sort(machines, machines + n); //给机器能力排序

        int res = 0;
        int cur_time = 0;
        while (true) {
            // cout<<Q_tasks.size()<<endl;
            cur_time++;

            V_tasks.clear();
            V_machine_can_use.clear();
            for (int i = 0; i < n; i++) {
                if (!machines[i].can_use) {
                    if (machines[i].over_time <=
                        cur_time) { //更新machines状态（到期）
                        machines[i].can_use = true;
                    }
                }
                if (machines[i].can_use) {
                    V_machine_can_use.push_back(i);
                }
            }
            if (V_machine_can_use.size() == n && Q_tasks.empty())
                break; //任务完成，机器都空闲，结束while
            int m_idx = 0;
            while (!Q_tasks.empty()) { //匹配每个任务
                Task tmp_task = Q_tasks.top();
                Q_tasks.pop();
                if (m_idx >= V_machine_can_use.size() ||
                    tmp_task.task_width > machines[V_machine_can_use[m_idx]]
                                              .width) { //当前任务现在无法处理
                    V_tasks.push_back(tmp_task);
                } else {
                    // cout<<"当前时间"<<cur_time<<endl;
                    // cout<<tmp_task.task_width<<":"<<tmp_task.task_time<<endl;
                    machines[V_machine_can_use[m_idx]].can_use = false;
                    machines[V_machine_can_use[m_idx]].over_time =
                        cur_time + tmp_task.task_time;
                    m_idx++;
                }
            }
            for (auto &x : V_tasks) { //将没法现在启动的任务重新加入队列
                Q_tasks.push(x);
            }
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
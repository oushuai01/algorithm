/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-26 09:19:29
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-26 09:20:54
 * @FilePath: \algorithm\LiKou\随想录\回溯\0_模板.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

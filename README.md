# Data-Structure
数据结构与算法

# 01-array
# 02-stack
# 03-queue
# 04-list
# 05-recursive
# 06-bst
# 07-set and map
## 存在warnings
# 08-heap

# 09-segment_tree
## 存在warnings

## 和区间数组的问题
## 解决办法
### range minimum query
### 树状数组

# 10-trie
## 优点

## 缺点

## 解决办法
### 压缩字典树
### 三分搜索书
### 后缀树
## 子串查询
### KMP
### Boyer-Moore
### Rabin-Karp
### 文件压缩的本质
### 编译原理
### DNA 🧬--->>>字符串匹配问题 

# 11-UnionFind

# 12-AVL
## 存在warnings
## 优化1
> 在计算每个节点的height信息时，当最下面的节点的高度信息不用调整的时候，在其上面的所有节点的 height 信息都不用调整，类似剪枝操作。


# 13-rb-tree

## 2-3tree
- 是一种绝对平衡的树
## 红黑树
### 性质 - 利用2-3树和红黑树是等价的就可以推到出来

- 每个节点或者是红色的，或者是黑色的
- 根节点是黑色的 
- 每一个叶子节点（最后的空节点）是黑色的
- 如果一个节点是红色的，那么他的孩子是黑色的
- 从任意一个节点到叶子节点，经过的黑色节点是一样的。
    - 由于2-3树是绝对平衡的，即从一个节点到任意一个叶子节点经过的路径是一样的。将其转换到红黑树中，不论在2-3树中经过的二节点还是三节点，二节点将转换为黑色，三节点也有一个节点转换为黑色，所以在红黑树中经过的黑色节点是一样的。即**红黑树保持“黑平衡”的二叉树， 黑色是绝对的平衡，严格意义上，不是平衡二叉树，最大的高度是2 * log(n)**
> 相比于AVL的查找性能更差，但是增加和删除操作的性能更加优秀。
### 添加操作
- 添加的时候，不会添加到空节点上，只能添加到叶子节点上。
- 如果叶子节点是一个二节点，则直接和叶子节点进行融合
- 如果叶子节点是一个三节点， 插入后进行融合成一个四节点，再进行拆分操作。
    - 如果拆分的是一个根节点，则直接提取中间的元素作为根节点。
    - 如果待拆分的节点是叶子节点，则分以下两种情况
        - 如果其父亲节点是一个二节点，则选取中间元素和其父亲节点进行融合。
        - 如果其父亲是一个三节点，则选取中间元素向父亲节点进行融合，融合后，父亲节点变成四节点，再对父亲节点进行拆分操作。

## b树
- 用于磁盘存储、数据库当中

# 14-hash-table
hash-table 主要关注的是1 hash 函数具体怎么设计，2是产生冲突后，如何避免冲突。
## hash函数怎么设计
- 键通过哈希函数得到的索引分布的越均匀越好。
- 对于一些特殊的领域， 有特殊的哈希函数设计，甚至还会有专门的论文研究哈希函数。
    - 对整形hash函数设计
        - 小范围正整数直接使用。
        - 小范围负整数进行偏移。
        - 大整数对某个数直接进行取模，对素数进行取模，取得的效果更好。
    - 浮点型
        - 转换成整型
    - 对字符串的hash函数设计
        - 转成整形进行处理
            - code = (c * 26^3 + o * 26^2 + d * 26^1 + e * 26^0) % M  //减少乘法运算
            - code = ((((c * B) + o ) * B + d) * B + e ) % M   //避免整形溢出
            - code = ((((c % M) * B) + o ) % M * B + d) % M * B + e ) % M
            - ```
            int hash = 0;
            for(char c : str)
                hash = (hash * B + c) % M; 
            ```
- hash 设计的原则
    - 1. 一致性：if a == b then hash(a) == hash(b)
    - 2. 高效性：计算高效简便
    - 3. 均匀性：哈希值分布均匀
## 产生冲突之后，怎么避免冲突
- 链地址法
    - (hashCode(k1) & 0x7fffffff) % M;
    - 开辟一个数组，在数组的每一个元素上使用一个链表，或者 treemap
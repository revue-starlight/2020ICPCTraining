# AC自动机
就是在树上KMP
## fail节点
假设已经会了kmp的核心思想，那么fail节点就是求从根节点到当前节点的这一字符串中的最长后缀是多少。然后fail节点指向这个最长后缀的末尾。<br>
比如是abcde，de那么这棵树就是 
![avatar](C:/Users/19606/Pictures/C2019y4/2.jpg)
## 优化
利用next数组将trie树写为trie图，
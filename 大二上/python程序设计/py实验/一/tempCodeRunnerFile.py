def dfs(graph):

    #将图形结构的结点转换成列表存储

    nodes = list(graph)

   

    #未访问的节点列表

    not_visited_nodes=[]

    #已访问的节点列表

    visited_nodes=[]

    #定义结点索引

    index = 0

    key = nodes[index]

    not_visited_nodes.append(key)

    

    while len(not_visited_nodes)!=0:

        top = not_visited_nodes.pop()

       

        visited_nodes.append(top)

        #处理邻接点

        for adj_node in graph[top]:

            if adj_node not in visited_nodes and adj_node not in not_visited_nodes:

                not_visited_nodes.append(adj_node)

                

            

    return visited_nodes   


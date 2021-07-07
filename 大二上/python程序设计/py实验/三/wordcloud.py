import jieba
import wordcloud
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib
matplotlib.rcParams['font.sans-serif'] = ['SimHei']


def getText(filepath):
    f = open(filepath, "r", encoding='utf-8', errors='ignore')
    text = f.read()
    f.close()
    return text

def getText_sanguo(filepath):
    f = open(filepath, "r", encoding='gb2312', errors='ignore')
    text = f.read()
    f.close()
    return text

def getName(filepath):
    Name = []
    try:
        file=open(filepath,"r")     #以读模式打开文件
    except FileNotFoundError:          #如果文件不存在，给提示
        print("file is not found")
    else:
        contents=file.readlines()       #读取全部行
        for content in contents:       #显示一行
            # print(content.split('\t')[0])   #每行用逗号分隔后，取第一个元素
            Name.append(content.split('\t')[0])
        return Name

def stopwordList(filepath):
    stopwords = [line.strip() for line in open(filepath,    'r', encoding='utf-8').readlines()]
    return stopwords

def wordFreq(filepath, text, topn):
    words = jieba.lcut(text.strip())
    counts = {}
    for word in words:
        if len(word) == 1:
            continue
        elif word not in stopwords:
            if word == "宋江道" or word == "宋公明":
                word = "宋江"
            if word == "智深" :
                word = "鲁智深"
            if word == "孔明" or word == "孔明曰":
                word = "诸葛亮"
            if word == "玄德" or word == "玄德曰" or word == "先主":
                word = "刘备"
            if word == "关公" or word == "关公曰" or word == "云长":
                word = "关羽"
            if word == "都督" :
                word = "周瑜"
            if word == "后主" :
                word = "刘禅"
            if word == "凤姐儿" or word == "凤姐":
                word ="王丹凤"
            if word == "二爷":
                word = "贾琏"
            if word == "黛玉":
                word = "林黛玉"
            counts[word] = counts.get(word, 0) + 1
    items= list(counts.items())
    items.sort(key = lambda x:x[1], reverse = True)
    f = open(filepath[:-4] + '_词频.txt', "w")
    for i in range(topn):
        word, count = items[i]
        f.writelines("{}\t{}\n".format(word, count))
    f.close()

def drowCloud():
    f = open("水浒传_词频.txt", "r")
    text = f.read()
    wcloud = wordcloud.WordCloud(font_path=r'C:\Windows\Fonts\simhei.ttf', background_color="white", width=1000, max_words=500, height=860, margin=2).generate(text)
    wcloud.to_file("水浒传cloud.png")

    f = open("三国演义_词频.txt", "r")
    text = f.read()
    wcloud = wordcloud.WordCloud(font_path=r'C:\Windows\Fonts\simhei.ttf', background_color="white", width=1000, max_words=500, height=860, margin=2).generate(text)
    wcloud.to_file("三国演义cloud.png")

    f = open("红楼梦_词频.txt", "r")
    text = f.read()
    wcloud = wordcloud.WordCloud(font_path=r'C:\Windows\Fonts\simhei.ttf', background_color="white", width=1000, max_words=500, height=860, margin=2).generate(text)
    wcloud.to_file("红楼梦cloud.png")
    f.close()

def drawRelationship(Names, filepath):
    f = open(filepath, 'r', encoding='utf-8') # 修改为filepath
    s = f.read()
    relations = {}
    lst_para = s.split('\n')
    for text in lst_para:
        for name1 in Names:
            if name1 in text:
                for name2 in Names:
                    if name2 in text and name1 != name2 and (name2, name1) not in relations:
                        relations[(name1, name2)] = relations.get((name1, name2), 0) + 1
    # print(relations.items())
    maxRela = max([v for k, v in relations.items()])
    relations = {k:v/maxRela for k, v in relations.items()}
    # print(relations)
    plt.figure(figsize=(15, 15))
    G = nx.Graph()
    for k,v in relations.items():
        G.add_edge(k[0], k[1], weight = v)
    elarge = [(u,v) for (u,v,d) in G.edges(data = True) if d['weight'] > 0.6]
    emidle = [(u,v) for (u,v,d) in G.edges(data = True) if (d['weight'] > 0.3) & (d['weight'] <=0.6)]
    esmall = [(u,v) for (u,v,d) in G.edges(data = True) if d['weight'] <= 0.3]

    pos = nx.circular_layout(G)
    nx.draw_networkx_nodes(G, pos, alpha = 0.8, node_size = 800)
    nx.draw_networkx_edges(G, pos, edgelist = elarge, width = 2.5, alpha = 0.9, edge_color = 'g')
    nx.draw_networkx_edges(G, pos, edgelist = emidle, width = 1.5, alpha = 0.6, edge_color = 'y')
    nx.draw_networkx_edges(G, pos, edgelist = esmall, width = 1, alpha = 0.4, edge_color = 'b', style = 'dashed')
    nx.draw_networkx_labels(G, pos, font_size = 12)
    plt.axis('off')
    plt.title("主要人物社交关系网络图")
    plt.show()

def drawRelationship_sanguo(Names, filepath):
    f = open(filepath, 'r',encoding='gb2312', errors='ignore') # 修改为filepath
    s = f.read()
    relations = {}
    lst_para = s.split('\n')
    for text in lst_para:
        for name1 in Names:
            if name1 in text:
                for name2 in Names:
                    if name2 in text and name1 != name2 and (name2, name1) not in relations:
                        relations[(name1, name2)] = relations.get((name1, name2), 0) + 1
    # print(relations.items())
    maxRela = max([v for k, v in relations.items()])
    relations = {k:v/maxRela for k, v in relations.items()}
    # print(relations)
    plt.figure(figsize=(15, 15))
    G = nx.Graph()
    for k,v in relations.items():
        G.add_edge(k[0], k[1], weight = v)
    elarge = [(u,v) for (u,v,d) in G.edges(data = True) if d['weight'] > 0.6]
    emidle = [(u,v) for (u,v,d) in G.edges(data = True) if (d['weight'] > 0.3) & (d['weight'] <=0.6)]
    esmall = [(u,v) for (u,v,d) in G.edges(data = True) if d['weight'] <= 0.3]

    pos = nx.circular_layout(G)
    nx.draw_networkx_nodes(G, pos, alpha = 0.8, node_size = 800)
    nx.draw_networkx_edges(G, pos, edgelist = elarge, width = 2.5, alpha = 0.9, edge_color = 'g')
    nx.draw_networkx_edges(G, pos, edgelist = emidle, width = 1.5, alpha = 0.6, edge_color = 'y')
    nx.draw_networkx_edges(G, pos, edgelist = esmall, width = 1, alpha = 0.4, edge_color = 'b', style = 'dashed')
    nx.draw_networkx_labels(G, pos, font_size = 12)
    plt.axis('off')
    plt.title("主要人物社交关系网络图")
    plt.show()


if __name__ == "__main__":

    text = getText(r"C:\Users\hanya\Desktop\CODE\python\python\水浒传.txt")
    stopwords = stopwordList(r"C:\Users\hanya\Desktop\CODE\python\python\水浒传停用词.txt")
    wordFreq(r"C:\Users\hanya\Desktop\CODE\python\python\水浒传.txt", text, 20)


    text = getText_sanguo(r"C:\Users\hanya\Desktop\CODE\python\python\三国演义.txt")
    stopwords = stopwordList(r"C:\Users\hanya\Desktop\CODE\python\python\三国演义停用词.txt")
    wordFreq(r"C:\Users\hanya\Desktop\CODE\python\python\三国演义.txt", text, 20)


    text = getText(r"C:\Users\hanya\Desktop\CODE\python\python\红楼梦.txt")
    stopwords = stopwordList(r"C:\Users\hanya\Desktop\CODE\python\python\红楼梦停用词.txt")
    wordFreq(r"C:\Users\hanya\Desktop\CODE\python\python\红楼梦.txt", text, 20)

    drowCloud()

    Names = getName(r"C:\Users\hanya\Desktop\CODE\python\python\红楼梦_词频.txt")
    drawRelationship(Names, r"C:\Users\hanya\Desktop\CODE\python\python\红楼梦.txt")

    Names = getName(r"C:\Users\hanya\Desktop\CODE\python\python\三国演义_词频.txt")
    drawRelationship_sanguo(Names, r"C:\Users\hanya\Desktop\CODE\python\python\三国演义.txt")

    Names = getName(r"C:\Users\hanya\Desktop\CODE\python\python\水浒传_词频.txt")
    drawRelationship(Names, r"C:\Users\hanya\Desktop\CODE\python\python\水浒传.txt")


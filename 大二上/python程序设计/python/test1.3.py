# coding=UTF-8
#!/usr/bin/env python3
import tkinter as tk
import math
from multiprocessing import Process
import os
from threading import Thread
from time import sleep
root = tk.Tk()
root.geometry("1000x800") #设置窗口的大小

canvas = tk.Canvas(root, width=1000, height=800, bg='white')  
canvas.pack(side=tk.LEFT)   #固定宽高


graph = {"1": ("2", "3", "4"),

         "2": ("1", "5", "3"),

         "3": ("1", "2", "6"),

         "4": ("1", "7"),

         "5": ("2", "8"),

         "6": ("3"),

         "7": ("4", "8"),

         "8": ("5", "7")}


x_center, y_center, x_add, y_add = 300, 300, 200, 100
graphPic = {
    "1": [x_center, y_center],

    "2": [300+x_add, y_center-y_add],

    "3": [300+x_add, y_center-2*y_add],

    "4": [300+x_add, y_center],

    "5": [300+x_add*2, y_center-y_add],

    "6": [300+x_add*2, y_center-2*y_add],

    "7": [300+x_add*2, y_center],

    "8": [300+x_add*3, y_center-y_add/2]
}

for k, v in graph.items():
    for v1 in v:
        canvas.create_line(graphPic[k][0], graphPic[k][1], graphPic[v1][0], graphPic[v1][1], width=6, fill='black')


for k, v in graph.items():
    for v1 in v:
        canvas.create_oval(graphPic[k][0], graphPic[k][1],graphPic[k][0]+60, graphPic[k][1]+60, fill='pink')
        canvas.create_text(graphPic[k][0], graphPic[k][1], text=k, font= 500, fill='red')

def dfs(graph):

    nodes = list(graph)

    not_visited_nodes = []

    visited_nodes = []

    index = 0

    key = nodes[index]

    not_visited_nodes.append(key)
    while len(not_visited_nodes) != 0:
        top = not_visited_nodes.pop()

        visited_nodes.append(top)
        canvas.create_oval(graphPic[top][0], graphPic[top][1],
                            graphPic[top][0] + 60, graphPic[top][1] + 60, fill='white')
        canvas.update()
        sleep(.8)
        canvas.create_oval(graphPic[top][0], graphPic[top][1],
                            graphPic[top][0] + 60, graphPic[top][1] + 60, fill='blue')
        canvas.update()
        for adj_node in graph[top]:

            if adj_node not in visited_nodes and adj_node not in not_visited_nodes:

                not_visited_nodes.append(adj_node)

    return visited_nodes


def bfs(graph):

    nodes = list(graph)

    first_element = nodes[0]

    not_visited_nodes = []

    visited_nodes = []

    depth = 1

    not_visited_nodes.append(first_element)

    while True:

        element = not_visited_nodes.pop(0)

        visited_nodes.append(element)
        canvas.create_oval(graphPic[element][0], graphPic[element][1],
                           graphPic[element][0] + 60, graphPic[element][1] + 60, fill='white')
        canvas.update()
        sleep(.8)
        canvas.create_oval(graphPic[element][0], graphPic[element][1],
                           graphPic[element][0] + 60, graphPic[element][1] + 60, fill='pink')
        canvas.update()
        edge_nodes = graph[element]

        for x in edge_nodes:

            if x not in visited_nodes and x not in not_visited_nodes:

                not_visited_nodes.append(x)

                depth = depth+1

        if len(not_visited_nodes) == 0:

            break

    return visited_nodes


def main():
    dfs(graph)
    sleep(.8)
    bfs(graph)
    root.mainloop()


if __name__ == "__main__":
    main()

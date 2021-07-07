# coding=UTF-8
#!/usr/bin/env python3
import tkinter as tk

def windowToCenter(root):
    width, height = 400, 440
    win_w, win_h = root.maxsize()
    win_x = int((win_w-width) / 2)
    win_y = int((win_h-height) / 2)
    root.geometry("{}x{}+{}+{}".format(width,height,win_x,win_y))

def drawCanvas(frame):
    canvas = tk.Canvas(frame, width=400, height=440)
    canvas.pack()
    canvas.create_text(200, 40, text="示例图形  ",
                       font=("微软雅黑", 18))
    canvas.create_rectangle(360, 400, 35, 80, outline="black")
    canvas.create_oval(360, 400, 35, 80, outline="black")
    canvas.create_oval(360, 400, 35, 80, outline="black")
    points = [60, 320, 200, 80, 335, 320]
    canvas.create_polygon(points, outline="black")

def main():
    window = tk.Tk()
    window.title("tkinter画图示例")
    window.resizable(width=False, height=False)
    windowToCenter(window)
    lframe = tk.LabelFrame(window)
    lframe.pack()
    drawCanvas(lframe)
    window.mainloop()

if __name__ == "__main__":
    main()
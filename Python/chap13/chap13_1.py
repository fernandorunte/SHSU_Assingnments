#programming exercises #1

import tkinter
import tkinter.messagebox

class MyGUI:
    def __init__(self):
        # Create the main window widget.
        self.main_window = tkinter.Tk()

        self.top_frame = tkinter.Frame()
        self.bottom_frame = tkinter.Frame()


        

        self.my_button = tkinter.Button(self.bottom_frame,
                                        text='Show Info',
                                        command=self.do_something)

        self.quit_button = tkinter.Button(self.bottom_frame,
                                          text='Quit',
                                          command=self.main_window.destroy)
        self.info = tkinter.StringVar()
        self.info_display = tkinter.Label(self.top_frame,textvariable=self.info)

        # Pack the Buttons.
        self.info_display.pack(side='top')
        self.my_button.pack(side='left')
        self.quit_button.pack(side='left')
        self.top_frame.pack()
        self.bottom_frame.pack()
        # Enter the tkinter main loop.
        tkinter.mainloop()

    def do_something(self):
        self.display= 'Steven Marcus \n 247 Bally Drive \n Waynesville, NC 27999'
        self.info.set(self.display)

        
test = MyGUI()

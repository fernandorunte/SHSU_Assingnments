import tkinter
import tkinter.messagebox

class MyGUI:
    def __init__(self):
        # Create the main window widget.
        self.main_window = tkinter.Tk()

        self.top_frame = tkinter.Frame()
        self.middle_frame = tkinter.Frame()
        self.bottom_frame = tkinter.Frame()


        self.info1 = tkinter.StringVar()
        self.info2 = tkinter.StringVar()
        self.info3 = tkinter.StringVar()

        self.sinister_button = tkinter.Button(self.top_frame,
                                        text='Sinister',
                                        command=self.display_sinister)

        self.dexter_button = tkinter.Button(self.middle_frame,
                                          text='Dexter',
                                          command=self.display_dexter)
        self.medium_button = tkinter.Button(self.bottom_frame,
                                          text='Medium',
                                          command=self.display_medium)
        
        self.info_display1 = tkinter.Label(self.top_frame,textvariable=self.info1)
        self.info_display2 = tkinter.Label(self.middle_frame,textvariable=self.info2)
        self.info_display3 = tkinter.Label(self.bottom_frame,textvariable=self.info3)
        # Pack the Buttons.
        self.sinister_button.pack(side='left')
        self.dexter_button.pack(side='left')
        self.medium_button.pack(side='left')
        
        self.info_display1.pack(side='left')
        self.info_display2.pack(side='left')
        self.info_display3.pack(side='left')
       
        
        self.top_frame.pack()
        self.middle_frame.pack()
        self.bottom_frame.pack()
        
        # Enter the tkinter main loop.
        tkinter.mainloop()

    def display_sinister(self):
        self.display1 = 'Left'
        self.info1.set(self.display1)
    def display_dexter(self):
        self.display2= 'Right'
        self.info2.set(self.display2)
    def display_medium(self):
        self.display3 = 'Center'
        self.info3.set(self.display3)
test = MyGUI()

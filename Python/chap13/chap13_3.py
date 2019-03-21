
import tkinter

class KiloConverterGUI:
    def __init__(self):

        # Create the main window.
        self.main_window = tkinter.Tk()

        # Create three frames to group widgets.
        self.top_frame = tkinter.Frame()
        self.mid_frame = tkinter.Frame()
        self.mid_frame2 = tkinter.Frame()
        self.bottom_frame = tkinter.Frame()

        # Create the widgets for the top frame.
        self.prompt_label1 = tkinter.Label(self.top_frame,
                    text='Enter mileage range for full tank: ')
                                        
        self.range_entry = tkinter.Entry(self.top_frame,
                                        width=10)

        # Pack the top frame's widgets.
        self.prompt_label1.pack(side='left')
        self.range_entry.pack(side='left')

        # Create the widgets for the middle frame.
        self.prompt_label2 = tkinter.Label(self.mid_frame,
                            text='Enter the gas amount in gallons: ')
        # We need a StringVar object to associate with
        # an output label. Use the object's set method
        # to store a string of blank characters.
        self.gas_entry = tkinter.Entry(self.mid_frame, width=10)

        # Pack the middle frame's widgets.
        self.prompt_label2.pack(side='left')
        self.gas_entry.pack(side='left')

        
        #create the button widgets for the middle_frame2
        self.mpgdisplay = tkinter.Label(self.mid_frame2,
                            text='Your mpg is: ')
        self.mpg = tkinter.StringVar()
        self.mpg_label = tkinter.Label(self.mid_frame2, textvariable=self.mpg)
        self.mpgdisplay.pack(side='left')
        self.mpg_label.pack(side='left')

        # Create the button widgets for the bottom frame.
        self.calc_button = tkinter.Button(self.bottom_frame,
                                          text='Calculate',
                                          command=self.convert)
        self.quit_button = tkinter.Button(self.bottom_frame,
                                          text='Quit',
                                          command=self.main_window.destroy)

        # Pack the buttons.
        self.calc_button.pack(side='left')
        self.quit_button.pack(side='left')

        # Pack the frames.
        self.top_frame.pack()
        self.mid_frame.pack()
        self.mid_frame2.pack()
        self.bottom_frame.pack()

        # Enter the tkinter main loop.
        tkinter.mainloop()

    # The convert method is a callback function for
    # the Calculate button.
    
    def convert(self):
        # Get the value entered by the user into the
        # kilo_entry widget.
        miles = float(self.range_entry.get())
        gallons = float(self.gas_entry.get())

        # Convert kilometers to miles.
        mpg = miles / gallons

        # Convert miles to a string and store it
        # in the StringVar object. This will automatically
        # update the miles_label widget.
        self.mpg.set(mpg)

# Create an instance of the KiloConverterGUI class.
kilo_conv = KiloConverterGUI()

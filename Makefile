CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Common/Label.o Common/border.o Common/Button.o Common/DotBorder.o Common/DblBorder.o Common/NormalBorder.o Common/TextBox.o Common/Panel.o Common/CheckList.o Common/CheckBox.o Common/NumericBox.o Common/ComboBox.o Common/RadioBox.o Common/RadioList.o Common/MassageBox.o

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe
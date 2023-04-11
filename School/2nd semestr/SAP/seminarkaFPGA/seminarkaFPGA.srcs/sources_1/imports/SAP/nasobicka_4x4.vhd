library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;
use IEEE.STD_LOGIC_arith.ALL;

entity nasobicka_4x4 is
    Port (  a0 : in  STD_LOGIC;
            a1 : in  STD_LOGIC;
            a2 : in  STD_LOGIC;
            a3 : in  STD_LOGIC;
            b0 : in  STD_LOGIC;
            b1 : in  STD_LOGIC;
            b2 : in  STD_LOGIC;
            b3 : in  STD_LOGIC;
            y0 : out  STD_LOGIC;
            y1 : out  STD_LOGIC;
            y2 : out  STD_LOGIC;
            y3 : out  STD_LOGIC;
            y4 : out  STD_LOGIC;
            y5 : out  STD_LOGIC;
            y6 : out  STD_LOGIC;
            y7 : out  STD_LOGIC
          );            
end nasobicka_4x4;

architecture rtl of nasobicka_4x4 is
signal y : std_logic_vector(7 downto 0);
signal a : std_logic_vector(3 downto 0);
signal b : std_logic_vector(3 downto 0);
begin	
	a(0) <= a0;
	a(1) <= a1;
	a(2) <= a2;
	a(3) <= a3;
	
	b(0) <= b0;
	b(1) <= b1;
	b(2) <= b2;
	b(3) <= b3;
	
	y <= a * b; -- tady je to slavné násobení
		
	y7 <= y(7);
	y6 <= y(6);
	y5 <= y(5);
	y4 <= y(4);
	y3 <= y(3);
	y2 <= y(2);
	y1 <= y(1);
	y0 <= y(0);
end rtl;

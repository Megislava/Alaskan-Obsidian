----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:04:08 03/28/2018 
-- Design Name: 
-- Module Name:    display_select - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity display_select is
	port(
			i0 : in std_logic;
			i1 : in std_logic;
			s0: out std_logic;
			s1: out std_logic;
			s2: out std_logic;
			s3: out std_logic
		);
end display_select;

architecture Behavioral of display_select is
begin

	s0 <= (not( not(i1) and not(i0) ));
	s1 <= (not( not(i1) and i0 ));
	s2 <= (not( i1 and not(i0) ));
	s3 <= (not( i1 and i0 ));
end Behavioral;


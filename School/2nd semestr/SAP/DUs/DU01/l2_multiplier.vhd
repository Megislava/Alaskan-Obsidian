library IEEE;
use IEEE.std_logic_1164.all;

-- Ports description - inputs a, b, c, d, outputs f, g
-- definice vstupu a vystupu - vstupy a, b, c, d, vystupy f, g
entity multiplier is
    port(
        a0    : in  std_logic;
        a1    : in  std_logic;
        b0    : in  std_logic;
        b1    : in  std_logic;
        y3	  : out std_logic
        y2	  : out std_logic
        y1	  : out std_logic
        y0	  : out std_logic
    );
end multiplier;

architecture behavioral of multiplier is
begin

-- you can use the following operators:
-- ----------------------------------
-- | operator |   example           |
-- ----------------------------------
-- |    and   | a and b and c       |
-- |    or    | a or b or (c and d) |
-- |    not   | not a               |
-- ----------------------------------
-- There is no priority of operators. Be sure to use brackets!
-- example:
--   given: f(a, b, c) = a * #b * #c + a * b
--   in VHDL: f <= (a and (not b) and (not c)) or (a and b)

-- ve vyrazech pouzivejte nasledujici operatory:
-- ----------------------------------
-- | operator | priklad pouziti     |
-- ----------------------------------
-- |    and   | a and b and c       |
-- |    or    | a or b or (c and d) |
-- |    not   | not a               |
-- ----------------------------------
-- pouzivejte zavorky!
-- priklad:
--   zadani: f(a, b, c) = a * #b * #c + a * b
--   ve VHDL: f <= (a and (not b) and (not c)) or (a and b)

-- another example:
-- jiny vzorovy priklad:
    y3 <= (not a) and b and c and d;
	y2 <= (a and b and d) or (b and (not c) and d);
	y1 <= ((not a) and (not c) and d) or ((not a) and (not b) and d) or (b and c and (not d)) or (a and b and c);
	y0 <= ((not a) and (not b) and c) or ((not a) and b and c);

end;

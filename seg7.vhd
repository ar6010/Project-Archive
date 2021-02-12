--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity seg7 is
port(
			 A: in std_logic_vector(31 downto 0);
			 SEG70: out std_logic_vector(7 downto 0);
			 SEG71: out std_logic_vector(7 downto 0);
			 SEG72: out std_logic_vector(7 downto 0);
			 SEG73: out std_logic_vector(7 downto 0);
			 SEG74: out std_logic_vector(7 downto 0);
			 SEG75: out std_logic_vector(7 downto 0)
);
end entity seg7;

architecture df of seg7 is

begin
 
with a(3 downto 0) select SEG70 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f
with a(7 downto 4) select SEG71 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f
with a(11 downto 8) select SEG72 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f
with a(15 downto 12) select SEG73 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f
with a(19 downto 16) select SEG74 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f
with a(23 downto 20) select SEG75 <=
                "01000000" when "0000", --0
                "01111001" when "0001", --1
                "10100100" when "0010", --2
                "10110000" when "0011", --3
                "10110000" when "0100", --4
                "10010010" when "0101", --5
                "10000010" when "0110", --6
                "11111000" when "0111", --7
                "10000000" when "1000", --8
                "10011000" when "1001", --9
                "10001000" when "1010", --a
                "10000011" when "1011", --b
                "10100111" when "1100", --c
                "10100001" when "1101", --d
                "10000110" when "1110", --e
                "10001110" when others; --f

                
end architecture df;

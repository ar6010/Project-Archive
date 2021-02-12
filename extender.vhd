--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity extender is

	port(
	
		imm: in std_logic_vector(23 downto 0);
		exts: in std_logic_vector(1 downto 0);
		imm32: out std_logic_vector(31 downto 0)
	
	);
	
end entity;

architecture df of extender is

begin

	imm32 <=
		x"000000" & imm(7 downto 0) when exts = b"00" else
		x"00000" & imm(11 downto 0) when exts = b"01" else
		imm(23) & imm(23) & imm(23) & imm(23) & imm(23) & imm(23) & imm(23 downto 0) & b"00";

end architecture;
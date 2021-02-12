--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity alu32 is 

port(

	a, b: in std_logic_vector(31 downto 0);
	alus: in std_logic_vector(2 downto 0);
	f: out std_logic_vector(31 downto 0);
	c, v, n, z: out std_logic

);

end entity;

architecture df of alu32 is 

signal inta, intb, intf: std_logic_vector(32 downto 0);
signal internal: std_logic_vector(65 downto 0);


begin

INTA(31 downto 0) <= A; 
INTA(32) <= '0'; 
INTB(31 downto 0) <= B; 
INTB(32) <= '0';
internal <= inta*intb;

with ALUS select intf <= --Works
 inta+intb when B"000",
 inta-intb when B"001",
 inta and intb when B"010", 
 inta or intb when B"011",
 inta xor intb when B"100",
 internal(32 downto 0) when B"101",
 intb when B"110",
 "000000000000000000000000000000001" when others;
 
 assign: process(all)
 
	begin
			c <= intf(32); --Works
			n <= intf(31);
			f <= intf(31 downto 0);
			
		if intf(31 downto 0) = "00000000000000000000000000000000" then
			z <= '1';
			else z <= '0';
			end if;
	
	end process;
	
	with alus select v <= 
			(inta(31) and intb(31) and not intf(31)) or (not inta(31) and not intb(31) and intf(31)) when B"000",
			(inta(31) and not intb(31) and not intf(31)) or (not inta(31) and intb(31) and intf(31)) when B"001",
			'0' when others;
 
 
 end architecture;
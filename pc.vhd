--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity pc is 

	port(
	
		d: in std_logic_vector(31 downto 0);
		ld,rst,clk: in std_logic;
		q: out std_logic_vector(31 downto 0)
	
	);
	
end entity;

architecture df of pc is 

begin

	memory: process(clk, rst, ld)
	begin
	
	if rst = '0' then q <= (others => '0');
		elsif rising_edge(clk) then
			if ld = '1' then q <= d;
			end if;
	end if;
		
	end process;

end architecture;
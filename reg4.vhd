--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity reg4 is

	port(
	
		d3,d2,d1,d0: in std_logic;
		rst, clk, ld: in std_logic;
		q3,q2,q1,q0: out std_logic
	
	);
	
end reg4;

architecture behav of reg4 is
begin

	memory: process(clk, rst, ld)
	begin
	
	if rst = '0' then q3 <= '0';q2 <= '0';q1 <= '0';q0 <= '0';
		elsif rising_edge(clk) then
			if ld = '1' then q3 <= d3;q2 <= d2;q1 <= d1;q0 <= d0;
			end if;
		end if;
		
	end process;

end architecture behav;
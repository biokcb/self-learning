#!/usr/bin/perl
use warnings;
use strict;
use File::Slurp;

print "\nsequence filename:";
chomp(my $file = <STDIN>);

my @sequences = read_file($file);
my $gc_num = 0;
my $seq_length=0;
my @gc_list = "start";
foreach (@sequences){
	chomp($_);
	if ($_ =~/>/){
	$_=~s/>//;
		if ($seq_length >= 1){
		my $gc_perc = ($gc_num / $seq_length)*100;
		push(@gc_list, $gc_perc);
		}
	push(@gc_list, $_);
	$gc_num = 0;
	$seq_length = 0;
	} else {
	my $numG = ($_ =~y/[Gg]//);
	my $numC = ($_=~y/[Cc]//);
	$gc_num = $gc_num + $numG + $numC;
	$seq_length = $seq_length + length($_);
	}
}

my $gc_perc = ($gc_num / $seq_length)*100;
push(@gc_list, $gc_perc);

my $gc_percent = 0;
my $i=0;
my $name = "none";

for ($i=1; defined($gc_list[$i]); $i+=2){
	if ($gc_list[$i+1] > $gc_percent){
	$name = $gc_list[$i];
	$gc_percent = $gc_list[$i+1];
	}
}

print "\n\n$name\n$gc_percent\n\n";
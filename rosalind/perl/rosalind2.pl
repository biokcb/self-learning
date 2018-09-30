#!/usr/bin/perl

print "\nsequence:";
my $seq = <STDIN>;

$seq =~s/T/U/g;
print $seq;
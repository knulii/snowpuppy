package com.snowpuppycoin.qt;

import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.File;

public class SnowpuppycoinQtActivity extends QtActivity
{
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		final File snowpuppycoinDir = new File(getFilesDir().getAbsolutePath() + "/.snowpuppycoincore");
		if (!snowpuppycoinDir.exists()) {
			snowpuppycoinDir.mkdir();
		}


		super.onCreate(savedInstanceState);
	}
}